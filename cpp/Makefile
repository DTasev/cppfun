all : boost_test 2dvector assign_arbitrary_size

# link as a separate step
boost_test : boost_test.cpp
	g++ -c -o boost_test.o boost_test.cpp
	g++ -o boost_test boost_test.o -L/usr/lib/x86_64-linux-gnu -lboost_regex

2dvector : 2dvector.cpp
	g++ -o 2dvector 2dvector.cpp -std=c++11

assign_arbitrary_size : assign_arbitrary_size.cpp
	g++ -o assign_arbitrary_size assign_arbitrary_size.cpp

auto_return_c++11 : auto_return_c++11.cpp
	g++ -o auto_return_c++11 auto_return_c++11.cpp -std=c++11

bool_vec_accumulate : bool_vec_accumulate.cpp
	g++ -o bool_vec_accumulate bool_vec_accumulate.cpp

const_example : const_example.cpp
	g++ -o const_example const_example.cpp

constructor_interrupt : constructor_interrupt.cpp
	g++ -o constructor_interrupt constructor_interrupt.cpp

cout_as_arg : cout_as_arg.cpp
	g++ -o cout_as_arg cout_as_arg.cpp

for_vs_transform : for_vs_transform.cpp
	g++ -o for_vs_transform for_vs_transform.cpp

implicit_move : implicit_move.cpp
	g++ -o implicit_move implicit_move.cpp

many_insertors : many_insertors.cpp
	g++ -o many_insertors many_insertors.cpp

omp_parallel : omp_parallel.cpp
	g++ -o omp_parallel omp_parallel.cpp

perf_return_val_vs_uptr : perf_return_val_vs_uptr.cpp
	g++ -o perf_return_val_vs_uptr perf_return_val_vs_uptr.cpp

return_unique_ptr_by_value : return_unique_ptr_by_value.cpp
	g++ -o return_unique_ptr_by_value return_unique_ptr_by_value.cpp

sorts : sorts.cpp
	g++ -o sorts sorts.cpp

static_assert_string_length : static_assert_string_length.cpp
	g++ -o static_assert_string_length static_assert_string_length.cpp

stdinvoke : stdinvoke.cpp
	g++ -o stdinvoke stdinvoke.cpp

stdref : stdref.cpp
	g++ -o stdref stdref.cpp

stl_print : stl_print.cpp
	g++ -o stl_print stl_print.cpp

test_scope : test_scope.cpp
	g++ -o test_scope test_scope.cpp

timeit : timeit.cpp timeit.h
	g++ -o timeit timeit.cpp