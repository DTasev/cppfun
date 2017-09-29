import cupy as cp


def printf(data):
    """
    Just a function showing that we can include things and printf from inside the CUDA execution
    """
    # Declaring a device function that prints shape
    f = cp.ElementwiseKernel(
        in_params='raw T in, int32 kernel, int32 kernel_width',
        out_params='raw T out',
        preamble=r"""
        #include <stdio.h> // we can include things
        """,
        operation=r"""
        printf(in[i]);
        """,
        name='median1d',
        options=('-std=c++11',)
    )

    f(data, size=data.size)
