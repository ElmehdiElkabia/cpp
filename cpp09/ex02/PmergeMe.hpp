#ifndef PMERGEME_HPP
#define PMERGEME_HPP


class PmergeMe
{
private:
	std::vector<int> c_vector;
	std::deque<int> c_deque;

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
    void makePairsVector(const std::vector<int> &input, std::vector< std::pair<int, int> > &pairs, bool &hasStraggler, int &straggler);
    void sortEachPairVector(std::vector< std::pair<int, int> > &pairs);
    void splitPairsVector(const std::vector< std::pair<int, int> > &pairs, std::vector<int> &small, std::vector<int> &big);
	void binaryInsertVector(std::vector<int> &sorted, int value);
	size_t binarySearchPositionVector(const std::vector<int> &sorted, int value) const;
    std::vector<size_t> buildJacobsthalOrder(size_t n) const;
	
    void sortDeque();

	std::deque<int> fordJohnsonDeque(const std::deque<int> &input);
    void makePairsDeque(const std::deque<int> &input, std::deque< std::pair<int, int> > &pairs, bool &hasStraggler, int &straggler);
    void sortEachPairDeque(std::deque< std::pair<int, int> > &pairs);
    void splitPairsDeque(const std::deque< std::pair<int, int> > &pairs, std::deque<int> &small, std::deque<int> &big);
	void binaryInsertDeque(std::deque<int> &sorted, int value);
	size_t binarySearchPositionDeque(const std::deque<int> &sorted, int value) const;

    double measureVectorSort();
    double measureDequeSort();
    
    bool isSortedVector(const std::vector<int> &vec) const;
    bool isSortedDeque(const std::deque<int> &deq) const;
};

#endif