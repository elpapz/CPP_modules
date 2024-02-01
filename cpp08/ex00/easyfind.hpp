#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Cannot reach that element!!");
		}
};

template<typename T>
typename T::iterator easyfind(T *array, int _n)
{
    typename T::iterator it;

    try
    {
        it = std::find(array->begin(), array->end(), _n);
        if (it == array->end())
            throw ::NotFoundException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (it);
}
#endif
