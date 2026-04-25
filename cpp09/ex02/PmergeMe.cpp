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

void PmergeMe::run(char **argv)
{
    parseInput(argv);
    printBefore();
    double vectorTime = measureVectorSort();
    double dequeTime = measureDequeSort();
    printAfter();
    printTimeVector(vectorTime);
    printTimeDeque(dequeTime);
}

void PmergeMe::parseInput(char **argv)
{
    std::string token;
    for (int i = 1; argv[i] != NULL; ++i)
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

int PmergeMe::toInt(const std::string &token) const
{
    try
    {
        long long value = std::strtoll(token.c_str(), NULL, 10);
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

bool PmergeMe::hasDuplicate(int value) const
{
    return std::find(c_vector.begin(), c_vector.end(), value) != c_vector.end();
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

void PmergeMe::printAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < c_vector.size(); ++i)
    {
        std::cout << c_vector[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printTimeVector(double time) const
{
    std::cout << "Time to process a range of " << c_vector.size() << " elements with std::vector: " << time << " seconds" << std::endl;
}

void PmergeMe::printTimeDeque(double time) const
{
    std::cout << "Time to process a range of " << c_deque.size() << " elements with std::deque: " << time << " seconds" << std::endl;
}

void PmergeMe::sortVector()
{
    // std::vector<int> sorted = c_vector;
    c_vector = fordJohnsonVector(c_vector);
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &input)
{
    if (input.size() <= 1)
        return input;
    std::vector< std::pair<int, int> > pairs;
    bool hasStraggler;
    int straggler;
    makePairsVector(input, pairs, hasStraggler, straggler);
    sortEachPairVector(pairs);
    std::vector<int> small, big;
    splitPairsVector(pairs, small, big);
    std::vector<int> sortedBig = fordJohnsonVector(big);
    for (size_t i = 0; i < small.size(); ++i)
    {
        InsertVector(sortedBig, small[i]);
    }
    if (hasStraggler)
    {
        InsertVector(sortedBig, straggler);
    }
    return sortedBig;
}

void PmergeMe::makePairsVector(const std::vector<int> &input, std::vector< std::pair<int, int> > &pairs, bool &hasStraggler, int &straggler)
{
    pairs.clear();
    hasStraggler = false;
    for (size_t i = 0; i < input.size() ; i += 2)
    {
        if (i + 1 < input.size())
        {
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        }
        else
        {
            hasStraggler = true;
            straggler = input[i];
        }
    }
}

void PmergeMe::sortEachPairVector(std::vector< std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size() ; ++i)
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

void PmergeMe::splitPairsVector(const std::vector< std::pair<int, int> > &pairs, std::vector<int> &small, std::vector<int> &big)
{
    small.clear();
    big.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }
}

void PmergeMe::InsertVector(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n) const
{
    std::vector<size_t> order;
    size_t j1 = 1, j2 = 1, j3 = 2;
    while (order.size() < n)
    {
        if (j1 < n)
            order.push_back(j1);
        if (j2 < n)
            order.push_back(j2);
        if (j3 < n)
            order.push_back(j3);
        size_t next = j1 + j2 + j3;
        j1 = j2;
        j2 = j3;
        j3 = next;
    }
    return order;
}

void PmergeMe::sortDeque()
{
    std::deque<int> sorted = c_deque;
    sorted = fordJohnsonDeque(sorted);
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &input)
{
    if (input.size() <= 1)
        return input;
    std::deque< std::pair<int, int> > pairs;
    bool hasStraggler;
    int straggler;
    makePairsDeque(input, pairs, hasStraggler, straggler);
    sortEachPairDeque(pairs);
    std::deque<int> small, big;
    splitPairsDeque(pairs, small, big);
    std::deque<int> sortedBig = fordJohnsonDeque(big);
    for (size_t i = 0; i < small.size(); ++i)
    {
        InsertDeque(sortedBig, small[i]);
    }
    if (hasStraggler)
    {
        InsertDeque(sortedBig, straggler);
    }
    return sortedBig;
}

void PmergeMe::makePairsDeque(const std::deque<int> &input, std::deque< std::pair<int, int> > &pairs, bool &hasStraggler, int &straggler)
{
    pairs.clear();
    hasStraggler = false;
    for (size_t i = 0; i < input.size() ; i += 2)
    {
        if (i + 1 < input.size())
        {
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
        }
        else
        {
            hasStraggler = true;
            straggler = input[i];
        }
    }
}

void PmergeMe::sortEachPairDeque(std::deque< std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size() ; ++i)
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

void PmergeMe::splitPairsDeque(const std::deque< std::pair<int, int> > &pairs, std::deque<int> &small, std::deque<int> &big)
{
    small.clear();
    big.clear();
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        small.push_back(pairs[i].first);
        big.push_back(pairs[i].second);
    }
}

void PmergeMe::InsertDeque(std::deque<int> &sorted, int value)
{
   	std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}


double PmergeMe::measureVectorSort()
{
    clock_t start = clock();
    sortVector();
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    return time;
}

double PmergeMe::measureDequeSort()
{
    clock_t start = clock();
    sortDeque();
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    return time;
}
