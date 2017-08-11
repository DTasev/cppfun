#include <utility>
#include <cstddef>
#include <string>

template< size_t N >
constexpr size_t length( char const (&)[N] )
{
	return N-1;
}

constexpr void check_assert(auto &&par){
	static_assert(length(par) > 3, "string length is not 3");
}

int main() {
	check_assert("123d");
	// your code goes here
	return 0;
}