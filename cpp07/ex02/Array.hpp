#ifndef ARRAY_HPP
#define ARRAY_HPP

//#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();
		Array &operator=(const Array& copy);
		T &operator[](unsigned int n);
		unsigned int size();
		T* getArray();

	private:
		unsigned int _n;
		T* array;
};

template<typename T>
Array<T>::Array() : _n(0), array(){}

template<typename T>
Array<T>::Array(unsigned int n) : _n(n), array(new T[n]){}

template<typename T>
Array<T>::Array(const Array<T>& copy)
{
	this->_n = copy._n;
	this->array = new T[copy._n];
	for(unsigned int i = 0; i < this->_n; i++)
		this->array[i] = copy.array[i];
}

template <typename T>
Array<T>::~Array()
{
	if (this->array)
		delete [] this->array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy)
{
	if (this->array)
		delete [] array;
	if (this->_n <= 0)
		return (*this);
	else
		for(unsigned int i = 0; i < this->_n; i++)
			this->array[i] = copy->array[i];
	return (*this);
}
template<typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= this->_n || !this->array)
		throw std::out_of_range("The position you are trying to access is not dynamicaly allocated\n");
	else
		return (this->array[n]);
}

template<typename T>
unsigned int Array<T>::size()
{
	return (this->_n);
}

template<typename T>
T* Array<T>::getArray()
{
	return(this->array);
}

#endif
