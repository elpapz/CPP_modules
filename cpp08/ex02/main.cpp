/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 05:29:17 by ade-pinh          #+#    #+#             */
/*   Updated: 2024/01/27 04:41:49 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "MutantStack.hpp"

int main()
{
	std::cout << "========Stack========" << std::endl;
	{
	    std::stack<int> s;
		std::stack<int> s2;

		s.push(10);
		s2.push(30);
		s.push(20);
		s2.push(20);
		s.push(30);
		s2.push(10);

		// c++ 11 elements
		// s.emplace(40);
		//s.swap(s2);
		std::cout << "Size: " <<  s.size() << std::endl;
		while (!s.empty())
		{
			std::cout << "Top: " << s.top() << std::endl;
			s.pop();
		}
	}

	std::cout << std::endl << "========deque========" << std::endl;

	{
		std::deque<int> d;
		std::deque<int> d2;

		d.push_front(10);
		d2.push_back(10);
		d.push_front(20);
		d2.push_back(20);
		d.push_front(30);
		d2.push_back(30);
		d.insert(d.end(), 40);


		d.swap(d2);
		d.swap(d2);
		// c++ 11 elements
		// d.emplace_back(50);
		// d.emplace_front(60);
		std::cout << "Size: " <<  d.size() << std::endl;

		for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
			std::cout << "Iterator: " << *it << std::endl;

		while (!d.empty())
		{
			std::cout << "Front: " << d.front() << std::endl;
			d.pop_front();
		}

		d.push_back(10);
		d.push_back(20);
		d.push_back(30);

		std::cout << "Size: " <<  d.size() << std::endl;

		for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
			std::cout << "Iterator: " << *it << std::endl;

		while (!d.empty())
		{
			std::cout << "Back: " << d.back() << std::endl;
			d.pop_back();
		}
	}

	std::cout << std::endl << "========MutantStack========" << std::endl;
	{
		MutantStack<int> s;
		MutantStack<int> s2;

		s.push(10);
		s2.push(30);
		s.push(20);
		s2.push(20);
		s.push(30);
		s2.push(10);
		s.insert(s.end(), 40);

		s.swap(s2);
		s.swap(s2);

		std::cout << "Size: " <<  s.size() << std::endl;
		for (MutantStack<int>::iterator it = s.begin(); it != s.end(); it++)
			std::cout << "Iterator: " << *it << std::endl;

		for(MutantStack<int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
			std::cout << "Reverse Iterator: " << *it << std::endl;

		for(MutantStack<int>::const_iterator it = s.begin(); it != s.end(); it++)
			std::cout << "Const Iterator: " << *it << std::endl;

		for(MutantStack<int>::const_reverse_iterator it = s.rbegin(); it != s.rend(); it++)
			std::cout << "Const Reverse Iterator: " << *it << std::endl;

		while (!s.empty())
		{
			std::cout << "Top: " << s.top() << std::endl;
			s.pop();
		}
	}

    return 0;
}

// #include <list>

// int main()
// {
// 	std::cout << "========MutantStack========" << std::endl;
// 	{
// 		MutantStack<int> mstack;
// 		mstack.push(5);
// 		mstack.push(17);
// 		std::cout << mstack.top() << std::endl;
// 		mstack.pop();
// 		std::cout << mstack.size() << std::endl;
// 		mstack.push(3);
// 		mstack.push(5);
// 		mstack.push(737);
// 		//[...]
// 		mstack.push(0);
// 		MutantStack<int>::iterator it = mstack.begin();
// 		MutantStack<int>::iterator ite = mstack.end();
// 		++it;
// 		--it;
// 		while (it != ite)
// 		{
// 		std::cout << *it << std::endl;
// 		++it;
// 		}
// 		std::stack<int> s(mstack);
// 	}
// 	std::cout << std::endl << "========List========" << std::endl;
// 	{
// 		std::list<int> mstack;
// 		mstack.push_back(5);
// 		mstack.push_back(17);
// 		std::cout << mstack.back() << std::endl;
// 		mstack.pop_back();
// 		std::cout << mstack.size() << std::endl;
// 		mstack.push_back(3);
// 		mstack.push_back(5);
// 		mstack.push_back(737);
// 		//[...]
// 		mstack.push_back(0);
// 		std::list<int>::iterator it = mstack.begin();
// 		std::list<int>::iterator ite = mstack.end();
// 		++it;
// 		--it;
// 		while (it != ite)
// 		{
// 		std::cout << *it << std::endl;
// 			++it;
// 		}
// 		//std::stack<int> s(mstack);
// 	}
// 	std::cout << std::endl << "========deque========" << std::endl;
// 	{
// 		std::deque<int> mstack;
// 		mstack.push_back(5);
// 		mstack.push_back(17);
// 		std::cout << mstack.back() << std::endl;
// 		mstack.pop_back();
// 		std::cout << mstack.size() << std::endl;
// 		mstack.push_back(3);
// 		mstack.push_back(5);
// 		mstack.push_back(737);
// 		//[...]
// 		mstack.push_back(0);
// 		std::deque<int>::iterator it = mstack.begin();
// 		std::deque<int>::iterator ite = mstack.end();
// 		++it;
// 		--it;
// 		while (it != ite)
// 		{
// 		std::cout << *it << std::endl;
// 			++it;
// 		}
// 		//std::stack<int> s(mstack);
// 	}
// 	return 0;
// }
