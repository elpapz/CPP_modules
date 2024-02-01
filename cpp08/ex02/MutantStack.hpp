#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
 #include <deque>
 #include <list>
 #include <stack>
 #include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{

   public:
       MutantStack();
       MutantStack(const MutantStack &copy);
       MutantStack &operator=(MutantStack const &copy);
       ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        const_iterator cbegin() const;
        const_iterator cend() const;
};

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    *this = copy;
}
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const &copy)
{
    if (this != &copy)
			this->Stack = copy.Stack;
		return (*this);
}
template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return (this->c.cend());
}

#endif
