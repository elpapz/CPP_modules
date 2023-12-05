#include <iostream>

void    checkInput(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong number of arguments!!" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!av[2])
    {
        std::cout << "The arguments can't be empty!\n";
        exit (EXIT_FAILURE);
    }
}

int main(int ac, char **av)
{
    checkInput(ac, av);

}