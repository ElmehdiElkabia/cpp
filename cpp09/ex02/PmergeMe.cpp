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

