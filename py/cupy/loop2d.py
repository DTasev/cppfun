import cupy as cp


def loop2d(data, kernel=3):
    """
    This should be doing a row-major traversal.
    The data is broadcast into a 1D array when transferred to the device.
    """
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
    # this is for the outer for loop, looping over the rows
    data_height = data.shape[1]
    # this is for the inner loop, looping over the columns
    data_width = data.shape[0]
    return f(data, data_width, kernel, kernel_width, size=data_height)
