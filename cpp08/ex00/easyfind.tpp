#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int f)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), f);
	if (it == container.end())
		throw NotFound();
	return (it);
}