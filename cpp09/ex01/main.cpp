#include "RPN.hpp"


int main(int ac, char **av)
{
    
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments";
        return(EXIT_SUCCESS);
    }
    try
    {
        RPN RPN;
        std::string name(av[1]);
        RPN.validate_input(av[1]);
        RPN.convert(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
