#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <exception>

template <class T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	virtual ~Array();

	Array &operator = (const Array &copy);
	T &operator [] (const size_t i) const;

	size_t size(void) const;
	void init(const size_t n);

private:
	T *_arr;
	size_t _len;
};

template <typename T>
void Array<T>::init(const size_t n)
{
	try
	{
		_arr = new T[n]();
		_len = n;
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << e.what() << '\n';
		_arr = NULL;
		_len = 0;
	}
}

template <typename T>
Array<T>::Array()
{
	init(0);
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	init(n);
}

template <typename T>
Array<T>::Array(const Array &copy) : _arr(NULL)
{
	*this = copy;
}

template <typename T>
Array<T> &Array<T>::operator = (const Array &copy)
{
	if (this != &copy)
	{
		delete[] _arr;
		init(copy._len);
		if (_arr)
		{
			for (size_t i = 0; i < copy._len; i++)
				_arr[i] = copy._arr[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
T &Array<T>::operator [] (const size_t i) const
{
	if (!_arr || i >= _len)
		throw (std::out_of_range("array index out of range, try again"));
	return (_arr[i]);
}

template <typename T>
std::ostream &operator << (std::ostream &stream, const Array<T> &array)
{
	std::cout << "size : " << array.size() << std::endl;
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i];
		if (i != array.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
	return (stream);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return (_len);
}

#endif