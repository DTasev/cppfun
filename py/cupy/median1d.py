import cupy as cp


def median1d(data, kernel=3):
    """
    Declaring a device function that prints shape
    because we accept the data as raw T, because of the raw specifically,
    we need to specify the size of the outer for loop with size=data.size in the
    function call
    """
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
