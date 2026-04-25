#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <limits>
#include <exception>

class PmergeMe
{
private:
	std::vector<int> c_vector;
	std::deque<int> c_deque;

	template <typename Container, typename PairContainer>
	Container fordJohnsonImpl(const Container &input) const;

	template <typename Container, typename PairContainer>
	void makePairsImpl(const Container &input, PairContainer &pairs, bool &hasStraggler, int &straggler) const;

	template <typename PairContainer>
	void sortEachPairImpl(PairContainer &pairs) const;

	template <typename PairContainer, typename Container>
	void splitPairsImpl(const PairContainer &pairs, Container &small, Container &big) const;

	template <typename Container>
	void insertImpl(Container &sorted, int value) const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe();

	void run(char **argv);
	void parseInput(char **argv);

	bool isValidInput(const std::string &token) const;
	int toInt(const std::string &token) const;
	bool hasDuplicate(int value) const;

	void printBefore() const;
	void printAfter() const;
	void printTimeVector(double time) const;
	void printTimeDeque(double time) const;

	void sortVector();
	std::vector<int> fordJohnsonVector(const std::vector<int> &input);
	std::vector<size_t> buildJacobsthalOrder(size_t n) const;

	void sortDeque();
	std::deque<int> fordJohnsonDeque(const std::deque<int> &input);

	double measureVectorSort();
	double measureDequeSort();
};

template <typename Container, typename PairContainer>
Container PmergeMe::fordJohnsonImpl(const Container &input) const
{
	if (input.size() <= 1)
		return input;
	PairContainer pairs;
	bool hasStraggler = false;
	int straggler = 0;
	makePairsImpl<Container, PairContainer>(input, pairs, hasStraggler, straggler);
	sortEachPairImpl<PairContainer>(pairs);
	Container small;
	Container big;
	splitPairsImpl<PairContainer, Container>(pairs, small, big);
	Container sortedBig = fordJohnsonImpl<Container, PairContainer>(big);
	std::vector<size_t> order = buildJacobsthalOrder(small.size());


	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		if (idx >= small.size() || idx >= big.size())
			continue;
		int value = small[idx];
		int partner = big[idx];

		typename Container::iterator partnerIt = std::find(sortedBig.begin(), sortedBig.end(), partner);
		typename Container::iterator insertPos;

		if (partnerIt != sortedBig.end())
			insertPos = std::lower_bound(sortedBig.begin(), partnerIt, value);
		else
			insertPos = std::lower_bound(sortedBig.begin(), sortedBig.end(), value);
		sortedBig.insert(insertPos, value);
	}

	if (hasStraggler)
		insertImpl<Container>(sortedBig, straggler);
	return sortedBig;
}

template <typename Container, typename PairContainer>
void PmergeMe::makePairsImpl(const Container &input, PairContainer &pairs, bool &hasStraggler, int &straggler) const
{
	pairs.clear();
	hasStraggler = false;
	for (size_t i = 0; i < input.size(); i += 2)
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

template <typename PairContainer>
void PmergeMe::sortEachPairImpl(PairContainer &pairs) const
{
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
}

template <typename PairContainer, typename Container>
void PmergeMe::splitPairsImpl(const PairContainer &pairs, Container &small, Container &big) const
{
	small.clear();
	big.clear();
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		small.push_back(pairs[i].first);
		big.push_back(pairs[i].second);
	}
}

template <typename Container>
void PmergeMe::insertImpl(Container &sorted, int value) const
{
	typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

#endif