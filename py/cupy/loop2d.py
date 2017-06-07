import cupy as cp


def loop2d(data, kernel=3):
    """
    This should be doing a row-major traversal.
    The data is broadcast into a 1D array when transferred to the device.
    """
    # allocate memory for the output parameter
    data_out = cp.zeros(data.shape, dtype=data.dtype)
    f = cp.ElementwiseKernel(
        in_params='raw T in, int32 width, int32 kernel, int32 kernel_width',
        out_params='raw T out',
        preamble=r"""
        #include <stdio.h> // for debug
        """,
        operation=r"""
        printf("index: %d\n", i);
        for(int j = 0; j < width; ++j){
            int pos = i * width + j;
            printf("value at %d: %d\n", pos, in[pos]);
            out[pos] = in[pos] + 3; // apply some operation
        }
        """,
        name='loop2d',
        options=('-std=c++11',),
        reduce_dims=False
    )
    if kernel <= 1:
        return data

    kernel_width = (kernel - 1) / 2
    # this is for the outer for loop, looping over the rows
    data_height = data.shape[1]
    # this is for the inner loop, looping over the columns
    data_width = data.shape[0]
    # we pass in data_out as the output parameter
    return f(data, data_width, kernel, kernel_width, data_out, size=data_height)
