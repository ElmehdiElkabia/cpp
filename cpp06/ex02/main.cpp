#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int i = std::rand() % 3;

	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else if (i == 2)
		return new C();
}
