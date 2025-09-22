#include "Replace.hpp"

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2) : filename(filename), s1(s1), s2(s2) {};

int Replace::run() const
{
	if (s1.empty())
	{
		std::cerr << "Error: (s1) must not be empty\n";
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: cannot open input file " << filename << std::endl;
		return 1;
	}
	std::string buffer;
	std::string line;

	while (std::getline(infile, line))
	{
		std::size_t start = 0;
		std::size_t pos;
		std::string processed;

		while ((pos = line.find(s1, start)) != std::string::npos)
		{
			processed.append(line.substr(start, pos - start));
			processed.append(s2);
			start = pos + s1.length();
		}
		processed.append(line.substr(start));

		buffer.append(processed + "\n");
	}
	infile.close();

	std::string outname = filename + ".replace";
	std::ofstream oufile(outname.c_str());
	if (!oufile)
	{
		std::cerr << "Error: cannot create output file " << outname << "\n";
		return 1;
	}

	oufile << buffer;
	oufile.close();
	return 0;
}