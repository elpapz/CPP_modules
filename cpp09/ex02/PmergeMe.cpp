# include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other) {*this = other;}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	return (*this);
}
clock_t PmergeMe::getVecStartTime(void){return (vectorStart);}

clock_t PmergeMe::getVecEndTime(void){return (vectorEnd);}

clock_t PmergeMe::getDequeStartTime(void){return (dequeStart);}

clock_t PmergeMe::getDequeEndTime(void){return (dequeEnd);}

void PmergeMe::initVector(int ac, char **av)
{
	this->vectorStart = clock();
	for (int i = 1; i < ac; i++)
		_vector.push_back(std::atoi(av[i]));
}

void PmergeMe::initDeque(int ac, char **av)
{
	this->dequeStart = clock();
	for (int i = 1; i < ac; i++)
		_deque.push_back(std::atoi(av[i]));
}

std::deque<int>& checkMerge(std::deque<int> &deq1, std::deque<int> &deq2)
{
	std::deque<int> deque;
	std::deque<int>::iterator it1 = deq1.begin();
	std::deque<int>::iterator it2 = deq2.begin();
	while (it1 != deq1.end() && it2 != deq2.end())
	{
		if (*it1 < *it2)
			deque.push_back(*it1++);
		else
			deque.push_back(*it2++);
	}
	while (it1 != deq1.end())
		deque.push_back(*it1++);
	while (it2 != deq2.end())
		deque.push_back(*it2++);
	return (deque);
}

std::vector<int>& checkMerge(std::vector<int> &vector1, std::vector<int> &vector2)
{
	std::vector<int> vector;
	std::vector<int>::iterator it1 = vector1.begin();
	std::vector<int>::iterator it2 = vector2.begin();
	while (it1 != vector1.end() && it2 != vector2.end())
	{
		if (*it1 < *it2)
			vector.push_back(*it1++);
		else
			vector.push_back(*it2++);
	}
	while (it1 != vector1.end())
		vector.push_back(*it1++);
	while (it2 != vector2.end())
		vector.push_back(*it2++);
	return (vector);
}

void SortVector(std::vector<int> &vector)
{
	if(vector.empty())
		return ;
	if (vector.size() <= 1)
		return ;
	if (vector.size() == 2)
	{
		if (vector[0] > vector[1])
		{
			int tmp = vector[0];
			vector[0] = vector[1];
			vector[1] = tmp;
		}
		return ;
	}
	std::vector<int> vec1;
	std::vector<int> vec2;
	for (size_t i = 0; i < vector.size() / 2; i++)
		vec1.push_back(vector[i]);
	for (size_t i = vector.size() / 2; i < vector.size(); i++)
		vec2.push_back(vector[i]);
	SortVector(vec1);
	SortVector(vec2);
	vector = checkMerge(vec1, vec2);
}

void SortDeque(std::deque<int> &deque)
{
	if(deque.empty())
		return ;
	if (deque.size() <= 1)
		return ;
	if (deque.size() == 2)
	{
		if (deque[0] > deque[1])
		{
			int tmp = deque[0];
			deque[0] = deque[1];
			deque[1] = tmp;
		}
		return ;
	}
	std::deque<int> deq1;
	std::deque<int> deq2;
	for (size_t i = 0; i < deque.size() / 2; i++)
		deq1.push_back(deque[i]);
	for (size_t i = deque.size() / 2; i < deque.size(); i++)
		deq2.push_back(deque[i]);
	SortDeque(deq1);
	SortDeque(deq2);
	deque = checkMerge(deq1, deq2);
}

void PmergeMe::startSorting(int ac, char **av)
{
	initDeque(ac, av);
	SortDeque(this->_deque);
	dequeEnd = clock();
	initVector(ac, av);
	SortVector(this->_vector);
	vectorEnd = clock();
}

const char* PmergeMe::wrongInput::what() const throw()
{
	return ("Your input is incorrect");
}
