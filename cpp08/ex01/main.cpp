#include "Span.hpp"

int main()
{

	Span a;

	Span b(a);

	a = b;

	Span c(b);

	return 0;

}
