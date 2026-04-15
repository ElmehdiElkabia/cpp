#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (this != &copy)
		*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		database = copy.database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream openfile(filename.c_str());

	if (!openfile.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		return;
	}
	std::string line;
	std::getline(openfile, line);
	while (std::getline(openfile, line))
	{
		size_t position = line.find(',');
		if (position == std::string::npos)
			continue;
		std::string datePart = line.substr(0, position);
		std::string pricePart = line.substr(position + 1);

		float price = std::strtof(pricePart.c_str(), NULL);
		database[datePart] = price;
	}
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream openfile(filename.c_str());

	if (!openfile.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		return;
	}
	std::string line;
	std::getline(openfile, line);
	if (line != "date | value")
	{
		std::cerr << "Error: line not following format 'date | value'\n";
		return;
	}
	std::string date;
	float value;
	while (std::getline(openfile, line))
	{
		if (!parseLine(line, date, value))
		{
			std::cerr << "Error: parsing line is false.\n";
			continue;
		}
		if (!isValidDate(date))
		{
			std::cerr << "Error: is not valid date.\n";
			continue;
		}
		if (!isValidValue(value))
		{
			std::cerr << "Error: is not valid value.\n";
			continue;
		}
	}
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, float &value) const
{
	size_t position = line.find('|');
	std::string datePart = line.substr(0,position);
	std::string valuePart = line.substr(position  - 1);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
}

bool BitcoinExchange::isValidValue(float value) const
{
}

// float BitcoinExchange::getExchangeRate(const std::string &date) const
// {
// }

// std::map<std::string, float>::const_iterator BitcoinExchange::getClosestDate(const std::string &date) const
// {
// }

// float BitcoinExchange::calculate(const std::string &date, float value) const
// {
// }

// void BitcoinExchange::printResult(const std::string &date, float value, float result) const
// {
// }

// void BitcoinExchange::handleError(const std::string &message) const
// {
// }

void BitcoinExchange::printDatabase() const
{
	for (std::map<std::string, float>::const_iterator it = database.begin(); it != database.end(); ++it)
		std::cout << it->first << " | " << it->second << std::endl;
}