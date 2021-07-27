#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(T &cont, int val)
{
	typename T::const_iterator found = std::find(cont.cbegin(), cont.cend(), val);
	if (found == cont.cend())
		throw (std::out_of_range("no such element"));
	return (found);
}

#endif