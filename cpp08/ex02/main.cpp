#include "MutantStack.hpp"
#include "list"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top=>" << mstack.top() << std::endl;

	mstack.pop();
	// std::cout << "top=>" << mstack.top() << std::endl;

	std::cout << "size=>" << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "top=>" << mstack.top() << std::endl;
	std::cout << "size=>" << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;

	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	/////////////////////////////////
	std::cout << "\n=========================================================\n";

	std::list<int> stack_list;

	stack_list.push_back(5);
	stack_list.push_back(17);

	std::cout << "top=>" << stack_list.back() << std::endl;

	stack_list.pop_back();

	std::cout << "size=>" << stack_list.size() << std::endl;

	stack_list.push_back(3);
	stack_list.push_back(5);
	stack_list.push_back(737);
	stack_list.push_back(0);

	std::cout << "top=>" << stack_list.back() << std::endl;
	std::cout << "size=>" << stack_list.size() << std::endl;

	std::list<int>::iterator itlist = stack_list.begin();
	std::list<int>::iterator itliste = stack_list.end();

	++itlist;

	--itlist;

	while (itlist != itliste)
	{
		std::cout << *itlist << std::endl;
		++itlist;
	}

	// std::stack<int> stack(stack_list);

	return 0;
}