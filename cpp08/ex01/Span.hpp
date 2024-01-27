/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 04:23:07 by ade-pinh          #+#    #+#             */
/*   Updated: 2024/01/21 05:24:01 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Span_H__
# define __Span_H__

# include <iostream>
# include <cstdlib>
# include <exception>
# include <algorithm>
# include <iterator>
# include <vector>

class Span
{
	private:
		unsigned int _n;
		unsigned int _size;
		int *_array;
	public:
		// Constructors
		Span();
		Span(unsigned int n);
		Span(const Span &cpy);
		// Operators
		Span &operator=(Span const &cpy);
		// Destructor
		~Span();

		void addNumber(int n);
		void addNumber(std::vector<int> range);
		int shortestSpan();
		int longestSpan();

		class ArrayFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class EmptyArrayException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
