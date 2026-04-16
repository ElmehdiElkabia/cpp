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
		float result = calculate(date,value);

		printResult(date, value, result);
	}
}

static std::string trim(const std::string &str)
{
	size_t start = 0;
	while (start < str.length() && std::isspace(str[start]))
		start++;

	size_t end = str.length();
	while (end > start && std::isspace(str[end - 1]))
		end--;

	return str.substr(start, end - start);
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, float &value) const
{
	size_t position = line.find('|');

	if (position == std::string::npos)
		return false;

	std::string datePart = trim(line.substr(0, position));
	if (datePart.empty())
		return false;

	std::string valuePart = trim(line.substr(position + 1));
	if (valuePart.empty())
		return false;

	char *end;
	double tmp = std::strtod(valuePart.c_str(), &end);

	if (end == valuePart.c_str())
		return false;

	while (*end)
	{
		if (!std::isspace(*end))
			return false;
		end++;
	}

	date = datePart;
	value = static_cast<float>(tmp);

	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return false;
	if (date[7] != '-' || date[4] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (leap)
			daysInMonth[1] = 29;
	}

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(float value) const
{
	if (value < 0)
		return false; //print "Error: not a positive number."
	if (value > 1000)
		return false; //print "Error: too large a number."
	return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = getClosestDate(date);

	if (it == database.end())
		throw std::runtime_error("Error: no exchange rate available for the given date.");
	return it->second;
}

std::map<std::string, float>::const_iterator BitcoinExchange::getClosestDate(const std::string &date) const
{
	if (database.empty())
		return database.end();
	
	std::map<std::string, float>::const_iterator it = database.lower_bound(date);

	if (it == database.begin() && it->first > date)
		return database.end();
	if (it != database.end() && it->first == date)
		return it;
	if (it == database.end() || it->first > date)
		--it;
	return it;
}

float BitcoinExchange::calculate(const std::string &date, float value) const
{
	float rate = getExchangeRate(date);

	return value * rate;
}

void BitcoinExchange::printResult(const std::string &date, float value, float result) const
{
	std::cout << date << " => " << value << " = " << result << std::endl;
}

// void BitcoinExchange::handleError(const std::string &message) const
// {
// }

void BitcoinExchange::printDatabase() const
{
	for (std::map<std::string, float>::const_iterator it = database.begin(); it != database.end(); ++it)
		std::cout << it->first << " | " << it->second << std::endl;
}