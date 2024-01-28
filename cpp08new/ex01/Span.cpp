#include "Span.hpp"


Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &copy) : _n(copy._n), data_stored(copy.data_stored) {}
Span &Span::operator=(Span const &copy)
{
    if(this != &copy)
    {
        this->_n = copy._n;
        this->data_stored = copy.data_stored;
    }
    return (*this);
}

Span::~Span() {}

unsigned int min(std::vector<int> a)
{
    int min = RAND_MAX;
    std::vector<int>::iterator it = a.begin();
        while (it != a.end())
        {
            if (std::abs(*it - *(it + 1)) < min)
			    min = std::abs(*it - *(it + 1));
            it++;
        }
        return ((unsigned int)min);
}

unsigned int Span::shortestSpan()
{
    if(this->_n <= 1)
        throw std::out_of_range("Not enough numbers to find a span");
    std::vector<int> tmp = this->data_stored;
    std::sort(tmp.begin(), tmp.end());
    unsigned int min_num = min(this->data_stored);
    return (min_num);
}

void Span::addSeveralNum(unsigned int n)
{
    std::srand(std::time(NULL));
    while (n > 0)
    {
        if (this->data_stored.size() >= this->_n)
            throw std::out_of_range("Your reached the limit of the storage space");
        data_stored.push_back(std::rand());
        n -= 1;
    }
}

void Span::addNumber(int num)
{
    if (this->data_stored.size() >= this->_n)
        throw std::out_of_range("Your reached the limit of the storage space");
    else
        this->data_stored.push_back(num);
}


unsigned int Span::longestSpan()
{
    if(this->_n <= 1)
        throw std::out_of_range("Not enough numbers to find a span");
    std::vector<int> tmp = this->data_stored;
    std::sort(tmp.begin(), tmp.end());
    unsigned int max_num = std::abs(*tmp.begin() - *(tmp.end() - 1));
    return (max_num);
}
