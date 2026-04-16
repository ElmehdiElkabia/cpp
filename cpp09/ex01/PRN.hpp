#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>


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
        int applyOperator(const std::string &op);
        void printResult() const;
}



#endif