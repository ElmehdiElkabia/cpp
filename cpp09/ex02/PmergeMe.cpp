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
	std::cout << "Time to process a range of " << c_vector.size() << " elements with std::vector: " << time << " us" << std::endl;
}

void PmergeMe::printTimeDeque(double time) const
{
	std::cout << "Time to process a range of " << c_deque.size() << " elements with std::deque: " << time << " us" << std::endl;
}

void PmergeMe::sortVector()
{
	c_vector = fordJohnsonVector(c_vector);
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &input)
{
	return fordJohnsonImpl<std::vector<int>, std::vector<std::pair<int, int> > >(input);
}

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n) const
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	const size_t jacob[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

	order.push_back(0);

	size_t prev = 1;

	for (size_t j = 0; j < sizeof(jacob) / sizeof(jacob[0]); ++j)
	{
		size_t current = jacob[j];

		if (prev >= n)
			break;

		if (current > n)
			current = n;

		for (size_t i = current; i > prev; --i)
			order.push_back(i - 1);

		prev = jacob[j];
	}

	return order;
}

void PmergeMe::sortDeque()
{
	c_deque = fordJohnsonDeque(c_deque);
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &input)
{
	return fordJohnsonImpl<std::deque<int>, std::deque<std::pair<int, int > > >(input);
}

double PmergeMe::measureVectorSort()
{
	clock_t start = clock();
	sortVector();
	clock_t end = clock();
	double time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
	return time;
}

double PmergeMe::measureDequeSort()
{
	clock_t start = clock();
	sortDeque();
	clock_t end = clock();
	double time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
	return time;
}
