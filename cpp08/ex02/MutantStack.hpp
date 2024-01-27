/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:29:14 by ade-pinh          #+#    #+#             */
/*   Updated: 2024/01/27 04:42:23 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MutantStack_H__
# define __MutantStack_H__

# include <iostream>
#include <iterator>
#include <stack>
#include <deque>
#include <vector>





template <typename T> class MutantStack : public std::stack<T>
{
	private:
		std::deque<T> _stack;

	public:
		MutantStack(void) : _stack() {};
		MutantStack(MutantStack const & src) : _stack(src._stack) {};
		MutantStack & operator=(MutantStack const & cp)
		{
			if (this != &cp)
				this->_stack = cp._stack;
			return (*this);
		};
		virtual ~MutantStack(void) {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) { return (this->_stack.begin()); };
		iterator end(void) { return (this->_stack.end()); };

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin(void) const { return (this->_stack.begin()); };
		const_iterator end(void) const { return (this->_stack.end()); };

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void) { return (this->_stack.rbegin()); };
		reverse_iterator rend(void) { return (this->_stack.rend()); };

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin(void) const { return (this->_stack.rbegin()); };
		const_reverse_iterator rend(void) const { return (this->_stack.rend()); };

		void push(T const & val) { this->_stack.push_back(val); };
		void pop(void) { this->_stack.pop_back(); };
		T & top(void) { return (this->_stack.back()); };
		T const & top(void) const { return (this->_stack.back()); };
		bool empty(void) const { return (this->_stack.empty()); };
		size_t size(void) const { return (this->_stack.size()); };
		void swap(MutantStack & x) { this->_stack.swap(x._stack); };
		void insert(iterator position, T const & val) { this->_stack.insert(position, val); };
};

#endif
