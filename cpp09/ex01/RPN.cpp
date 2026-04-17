#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		this->numbers = copy.numbers;
	return *this;
}

RPN::~RPN() {}

void RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		if (token.empty())
			continue;
		processToken(token);
	}

	if (numbers.size() != 1)
		throw std::runtime_error("Error");
	printResult();
}

void RPN::processToken(const std::string &token)
{
	if (isOperator(token))
	{
		applyOperator(token);
		return;
	}
	if (token.length() != 1 || token[0] < '0' || token[0] > '9')
		throw std::runtime_error("Error");
	numbers.push(token[0] - '0');
}

bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::applyOperator(const std::string &op)
{
	if (numbers.size() < 2)
		throw std::runtime_error("Error");
	int result;
	int right = numbers.top();
	numbers.pop();
	int left = numbers.top();
	numbers.pop();
	if (op == "+")
		result = left + right;
	else if (op == "-")
		result = left - right;
	else if (op == "*")
		result = left * right;
	else if (op == "/")
	{
		if (right == 0)
			throw std::runtime_error("Error");
		result = left / right;
	}
	numbers.push(result);
}

void RPN::printResult() const
{
	int result = numbers.top();

	std::cout << result << std::endl;
}