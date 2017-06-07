import cupy as cp


def loop2d(data, kernel=3):
    f = cp.ElementwiseKernel(
        in_params='raw T in, int32 width, int32 kernel, int32 kernel_width',
        out_params='raw T out',
        preamble=r"""
        #include <stdio.h>
        """,
        operation=r"""
        for(int j = 0; j < width; ++j){
            int pos = i*j+j;
            printf("value at %d: %d\n", pos, in[pos]);
        }
        """,
        name='loop2d',
        options=('-std=c++11',)
    )
    if kernel <= 1:
        return data

    kernel_width = (kernel - 1) / 2

    return f(data, data.shape[0], kernel, kernel_width, size=data.shape[1])
