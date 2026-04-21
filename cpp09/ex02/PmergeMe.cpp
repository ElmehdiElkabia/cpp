#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
    {
        c_vector = copy.c_vector;
        c_deque = copy.c_deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidInput(const std::string &token) const
{
    if (token.empty())
        return false;
    for (size_t i = 0; i < token.size(); ++i)
    {
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;
}

void PmergeMe::parseInput(char **argv)
{
    std::string token;
    for (int i = 1; argv[i] != nullptr; ++i)
    {
        token = argv[i];
        if (!isValidInput(token))
        {
            std::cerr << "Error: Invalid input '" << token << "'. Only positive integers are allowed." << std::endl;
            exit(EXIT_FAILURE);
        }
        int value = toInt(token);
        if (hasDuplicate(value))
        {
            std::cerr << "Error: Duplicate value '" << value << "' found." << std::endl;
            exit(EXIT_FAILURE);
        }
        c_vector.push_back(value);
        c_deque.push_back(value);
    }
}