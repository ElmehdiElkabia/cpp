#include "RPN.hpp"


RPN::RPN(){}

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

RPN::~RPN(){}

void RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (getline(iss, token,' '))
        processToken(token);
}

void RPN::processToken(const std::string &token)
{
    
}