#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> database;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange();

	void loadDatabase(const std::string &filename);
	void processInput(const std::string &filename);

	bool parseLine(const std::string &line, std::string &date, float &value) const;
	bool isValidDate(const std::string &date) const;
	bool isValidValue(float value) const;

	// float getExchangeRate(const std::string &date) const;
	// std::map<std::string, float>::const_iterator getClosestDate(const std::string &date) const;

	// float calculate(const std::string &date, float value) const;
	// void printResult(const std::string &date, float value, float result) const;
	// void handleError(const std::string &message) const;


	void printDatabase() const;
};

#endif