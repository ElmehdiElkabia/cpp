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

bool PmergeMe::hasDuplicate(int value) const
{
    return std::find(c_vector.begin(), c_vector.end(), value) != c_vector.end();
}

int PmergeMe::toInt(const std::string &token) const
{
    try
    {
        long long value = std::stoll(token);
        if (value < 0 || value > std::numeric_limits<int>::max())
            throw std::out_of_range("Value out of range");
        return static_cast<int>(value);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << " for input '" << token << "'." << std::endl;
        exit(EXIT_FAILURE);
    }
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

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < c_vector.size(); ++i)
    {
        std::cout << c_vector[i] << " ";
    }
    std::cout << std::endl;
}