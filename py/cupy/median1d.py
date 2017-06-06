import cupy as cp


def median1d(data, kernel=3):
    # Declaring a device function that prints shape
    f = cp.ElementwiseKernel(
        in_params='raw T in, int32 kernel, int32 kernel_width',
        out_params='raw T out',
        operation=r"""
        if(i > kernel_width && i < _ind.size() - kernel_width){
            float total = 0;
            for(int ki = -kernel_width; ki <= kernel_width; ++ki){
                total += in[i+ki];
            }
            out[i] = (total / kernel);
        }else{
            out[i] = in[i];
        }
        """,
        name='median1d',
        options=('-std=c++11',)
    )
    if kernel <= 1:
        return data

    kernel_width = (kernel - 1) / 2
    return f(data, kernel, kernel_width, data.size, size=data.size)


def median1d2(data, kernel=3):
    # Declaring a device function that prints shape
    f = cp.ElementwiseKernel(
        in_params='raw T in, int32 kernel, int32 kernel_width, int32 max_idx',
        out_params='raw T out',
        preamble=r"""
        #include <stdio.h>
        """,
        operation=r"""
        float total = 0;
        for(int ki = -kernel_width; ki <= kernel_width; ++ki){
            int pos = i+ki > max_idx ? max_idx : i+ki < 0 ? 0 : i+ki;
            printf("pos: %d\n", pos);
            total += in[pos];
        }
        printf("total: %f\n", total);
        out[i] = total > 0 ? (total / kernel) : 0;
        """,
        name='median1d2',
        options=('-std=c++11',)
    )
    if kernel <= 1:
        return data

    kernel_width = (kernel - 1) / 2
    return f(data, kernel, kernel_width, data.size - 1, size=data.size)
