#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers...>" << std::endl;
        return 1;
    }
    PmergeMe sorter;
    sorter.run(argv);

    return 0;
}