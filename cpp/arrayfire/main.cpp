#include <arrayfire.h>
// 1. Add the af/opencl.h include to your project
#include <af/opencl.h>
int main() {
    size_t length = 10;
    // Create ArrayFire array objects:
    af::array A = af::randu(length, f32);
    af::array B = af::constant(0, length, f32);
    // ... additional ArrayFire operations here
    // 2. Obtain the device, context, and queue used by ArrayFire
    static cl_context af_context = afcl::getContext();
    static cl_device_id af_device_id = afcl::getDeviceId();
    static cl_command_queue af_queue = afcl::getQueue();
    // 3. Obtain cl_mem references to af::array objects
    cl_mem * d_A = A.device<cl_mem>();
    cl_mem * d_B = B.device<cl_mem>();
    // 4. Load, build, and use your kernels.
    //    For the sake of readability, we have omitted error checking.
    int status = CL_SUCCESS;
    // A simple copy kernel, uses C++11 syntax for multi-line strings.
    const char * kernel_name = "copy_kernel";
    const char * source = R"(
        void __kernel
        copy_kernel(__global float * gA, __global float * gB)
        {
            int id = get_global_id(0);
            gB[id] = gA[id];
        }
    )";
    // Create the program, build the executable, and extract the entry point
    // for the kernel.
    cl_program program = clCreateProgramWithSource(af_context, 1, &source, NULL, &status);
        status = clBuildProgram(program, 1, &af_device_id, NULL, NULL, NULL);
    cl_kernel kernel = clCreateKernel(program, kernel_name, &status);
    // Set arguments and launch your kernels
    clSetKernelArg(kernel, 0, sizeof(cl_mem), d_A);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), d_B);
        clEnqueueNDRangeKernel(af_queue, kernel, 1, NULL, &length, NULL, 0, NULL, NULL);
    // 5. Return control of af::array memory to ArrayFire
    A.unlock();
    B.unlock();
    // ... resume ArrayFire operations
    // Because the device pointers, d_x and d_y, were returned to ArrayFire's
    // control by the unlock function, there is no need to free them using
    // clReleaseMemObject()
    return 0;
}