#include "easyfind.hpp"
#include <vector>
# include <cstdlib>
# include <exception>
# include <iterator>
# include <algorithm>

int main(void)
{
    int num[] = {1, 2, 37, 42, 53, 6, 7, 8, 95};
    std::vector<int> v(num, num + sizeof(num) / sizeof(*num));
    for (int i = 0; i < 11; i++)
    {
        std::vector<int>::iterator it = easyfind(&v, i);
        if (it != v.end())
            std::cout << *easyfind(&v, i) << std::endl;
    }
}
