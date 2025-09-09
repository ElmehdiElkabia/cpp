#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1 || !argv)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] = toupper(argv[i][j]);
		}
		std::cout << argv[i];
	}
	std::cout << std::endl;
}