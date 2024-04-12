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
		std::vector<int> _vector;
		std::deque<int> _deque;
		clock_t vectorStart;
		clock_t vectorEnd;
		clock_t dequeStart;
		clock_t dequeEnd;
		int _size;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(PmergeMe const &other);
		clock_t getVecStartTime(void);
		clock_t getVecEndTime(void);
		clock_t getDequeStartTime(void);
		clock_t getDequeEndTime(void);
		void sortVector(std::vector<int> &vector);
		void initVector(int ac, char **av);
		void initDeque(int ac, char **av);
		void SortDeque(std::deque<int> &deque);
		std::deque<int>& checkMerge(std::deque<int> &deq1, std::deque<int> &deq2);
		void sortMerge(std::deque<int> &deque);
		void sortVector(std::vector<int> &vector);
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