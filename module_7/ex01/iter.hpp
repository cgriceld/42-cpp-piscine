#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>
void iter(const T *arr, const size_t len, void (*f)(const T &a))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif