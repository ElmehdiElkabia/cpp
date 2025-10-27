#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cerr << "Usage: ./ex04 <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if (!argv[1] || !argv[2])
	{
		std::cerr << "Error: Arguments cannot be NULL!" << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: Search string (s1) cannot be empty!" << std::endl;
		return 1;
	}
	std::ifstream readfile(argv[1]);
	if (!readfile.is_open())
	{
		std::cerr << "Error opening input file!" << std::endl;
		return 1;
	}

	std::stringstream buffer;
	buffer << readfile.rdbuf();
	std::string result = buffer.str();

	size_t pos = 0;

	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	}

	std::string filename = std::string(argv[1]) + ".replace";
	std::ofstream outputfile(filename.c_str());
	if (!outputfile.is_open())
	{
		std::cerr << "Error opening output file!" << std::endl;
		return 1;
	}
	outputfile << result;
	std::cout << "Data written to " << filename << std::endl;
}
