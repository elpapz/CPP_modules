/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:28:03 by ade-pinh          #+#    #+#             */
/*   Updated: 2024/01/21 05:25:17 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _size(0), _array(new int[0]) {}

Span::Span(unsigned int n) : _n(n), _size(0), _array(new int[n])
{
	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = 0;
}

Span::Span(const Span &cpy)
{
	*this = cpy;
}

Span &Span::operator=(Span const &cpy)
{
	if (this != &cpy)
	{
		if (this->_array)
			delete [] this->_array;
		this->_n = cpy._n;
		this->_size = cpy._size;
		this->_array = new int[_n];
		for (unsigned int i = 0; i < _n; i++)
			this->_array[i] = cpy._array[i];
	}
	return *this;
}

Span::~Span()
{
	delete [] _array;
}

void Span::addNumber(int n)
{
	if (this->_size >= _n)
		throw ArrayFullException();
	this->_array[this->_size] = n;
	this->_size++;
}

void Span::addNumber(std::vector<int> begin)
{
	if (this->_size + (unsigned int)(sizeof(begin.begin()) / sizeof(begin[0])) >= _n)
		throw ArrayFullException();
	for (std::vector<int>::iterator it = begin.begin(); it != begin.end(); it++)
	{
		this->_array[this->_size] = *it;
		this->_size++;
	}
}

int Span::shortestSpan()
{
	if (this->_size <= 1)
		throw EmptyArrayException();
	std::vector<int> vec(this->_array, this->_array + this->_size);
	std::sort(vec.begin(), vec.end());
	int min = 2147483647;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (abs(*it - *(it + 1)) < min)
			min = abs(*it - *(it + 1));
	}
	return min;
}

int Span::longestSpan()
{
	if (_size <= 1)
		throw EmptyArrayException();
	std::vector<int> vec(this->_array, this->_array + this->_size);
	std::vector<int>::iterator min = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator max = std::max_element(vec.begin(), vec.end());
	return abs(*max - *min);
}

const char *Span::ArrayFullException::what() const throw()
{
	return "Array is full";
}

const char *Span::EmptyArrayException::what() const throw()
{
	return "Array is empty";
}
