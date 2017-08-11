BUILD_FOLDER = build


all : build_prep boost_test 2dvector assign_arbitrary_size auto_return_c++11 bool_vec_accumulate const_example constructor_interrupt cout_as_arg for_vs_transform implicit_move many_insertors omp_parallel perf_return_val_vs_uptr return_unique_ptr_by_value sorts static_assert_string_length stdref stl_print timeit two_semicol_namespace uname_linux unpack_tuple

build_prep :
	mkdir $(BUILD_FOLDER)
# link as a separate step
boost_test : boost_test.cpp
	g++ -o $(BUILD_FOLDER)/boost_test.o boost_test.cpp -c
	g++ -o $(BUILD_FOLDER)/boost_test boost_test.o -L/usr/lib/x86_64-linux-gnu -lboost_regex

2dvector : 2dvector.cpp
	g++ -o $(BUILD_FOLDER)/2dvector 2dvector.cpp -std=c++11

assign_arbitrary_size : assign_arbitrary_size.cpp
	g++ -o $(BUILD_FOLDER)/assign_arbitrary_size assign_arbitrary_size.cpp -std=c++11

auto_return_c++11 : auto_return_c++11.cpp
	g++ -o $(BUILD_FOLDER)/auto_return_c++11 auto_return_c++11.cpp -std=c++11

bool_vec_accumulate : bool_vec_accumulate.cpp
	g++ -o $(BUILD_FOLDER)/bool_vec_accumulate bool_vec_accumulate.cpp -std=c++11

const_example : const_example.cpp
	g++ -o $(BUILD_FOLDER)/const_example const_example.cpp -std=c++11

constructor_interrupt : constructor_interrupt.cpp
	g++ -o $(BUILD_FOLDER)/constructor_interrupt constructor_interrupt.cpp -std=c++11

cout_as_arg : cout_as_arg.cpp
	g++ -o $(BUILD_FOLDER)/cout_as_arg cout_as_arg.cpp

for_vs_transform : for_vs_transform.cpp
	g++ -o $(BUILD_FOLDER)/for_vs_transform for_vs_transform.cpp -std=c++11

implicit_move : implicit_move.cpp stl_print.h
	g++ -o $(BUILD_FOLDER)/implicit_move implicit_move.cpp -std=c++11

many_insertors : many_insertors.cpp
	g++ -o $(BUILD_FOLDER)/many_insertors many_insertors.cpp -std=c++11

omp_parallel : omp_parallel.cpp
	g++ -o $(BUILD_FOLDER)/omp_parallel omp_parallel.cpp

perf_return_val_vs_uptr : perf_return_val_vs_uptr.cpp timeit.h stl_print.h
	g++ -o $(BUILD_FOLDER)/perf_return_val_vs_uptr perf_return_val_vs_uptr.cpp -std=c++14

return_unique_ptr_by_value : return_unique_ptr_by_value.cpp
	g++ -o $(BUILD_FOLDER)/return_unique_ptr_by_value return_unique_ptr_by_value.cpp -std=c++14

sorts : sorts.cpp
	g++ -o $(BUILD_FOLDER)/sorts sorts.cpp -std=c++11

static_assert_string_length : static_assert_string_length.cpp
	g++ -o $(BUILD_FOLDER)/static_assert_string_length static_assert_string_length.cpp -std=c++14

stdref : stdref.cpp
	g++ -o $(BUILD_FOLDER)/stdref stdref.cpp -std=c++14

stl_print : stl_print.h
	g++ -o $(BUILD_FOLDER)/stl_print stl_print.h -std=c++11

timeit : timeit.cpp timeit.h
	g++ -o $(BUILD_FOLDER)/timeit timeit.cpp -std=c++11

two_semicol_namespace : two_semicol_namespace.cpp
	g++ -o $(BUILD_FOLDER)/two_semicol_namespace two_semicol_namespace.cpp

uname_linux : uname_linux.cpp
	g++ -o $(BUILD_FOLDER)/uname_linux uname_linux.cpp -std=c++11

unpack_tuple : unpack_tuple.cpp
	g++ -o $(BUILD_FOLDER)/unpack_tuple unpack_tuple.cpp -std=c++11