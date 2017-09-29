cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE(ArrayFire)
INCLUDE_DIRECTORIES(${ArrayFire_INCLUDE_DIRS})

FIND_PACKAGE(OpenCL)
SET(EXTRA_LIBS ${CMAKE_THREAD_LIBS_INIT} ${OpenCL_LIBRARIES})

add_executable(main main.cpp)

if(DEFINED ENV{GPU})
    message("Linking GPU backend")
    target_link_libraries(main ${ArrayFire_CUDA_LIBRARIES} ${EXTRA_LIBS})
else()
    message("Linking OpenCL backend")
    target_link_libraries(main ${ArrayFire_OpenCL_LIBRARIES} ${EXTRA_LIBS})
endif()
