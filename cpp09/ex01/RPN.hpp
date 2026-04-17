#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <exception>


class RPN
{
    private:
        std::stack<int> numbers;
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();

        void evaluate(const std::string &expression);
        void processToken(const std::string &token);
        bool isOperator(const std::string &token) const;
        void applyOperator(const std::string &op);
        void printResult() const;
};



#endif