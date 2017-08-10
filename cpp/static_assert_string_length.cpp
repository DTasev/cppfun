#include <utility>
#include <cstddef>
#include <string>

template< size_t N >
constexpr size_t length( char const (&)[N] )
{
	return N-1;
}

constexpr void check_assert(char const * &&par){
	static_assert( length(par) > 3, "string length is not 3" );
}

int main() {
	check_assert("1233");
	// your code goes here
	return 0;
}