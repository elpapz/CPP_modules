#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>
# include <vector>
# include <deque>
# include <ctime>
# include <limits.h>

class PmergeMe
{
	private:
		std::vector<int> *_vector;
		std::deque<int> *_deque;
		clock_t vectorStart;
		clock_t vectorEnd;
		clock_t dequeStart;
		clock_t dequeEnd;
		int size;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(PmergeMe const &other);
		void initVector(int ac, char **av);
		void initDeque(int ac, char **av);
		void sortDeque(std::deque<int> &deque);
		void sortVector(std::vector<int> &vector);
		void printSorted(void);
		void countainersData(void);
		void startSorting(int, char **);
		class wrongInput : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class notNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
