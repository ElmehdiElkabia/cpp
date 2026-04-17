#include "RPN.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN number number operator" << std::endl;
		return (1);
	}

	try
	{
		RPN rpn;

		rpn.evaluate(argv[1]);

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}