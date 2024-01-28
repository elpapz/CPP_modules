#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <cstdlib>
# include <exception>
# include <algorithm>
# include <iterator>
# include <vector>
#include <climits>
#include <ctime>

class Span
{
   private:
    unsigned int _n;
    std::vector<int> data_stored;

   public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(Span const &copy);
        ~Span();
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addNumber(int num);
        void printNumbers();
        void addSeveralNum(unsigned int n);
};

#endif
