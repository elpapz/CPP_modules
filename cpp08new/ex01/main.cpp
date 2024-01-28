#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "\n\n\n";

        Span sp1 = Span(10000);
        sp1.addSeveralNum(10000);
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
   try
    {
        int n = 10000;
        Span span2(n);
        for(int i = 0; i < n; i++)
        {
            span2.addNumber(std::rand());
        }
        std::cout << "\n\n\n10000 numbers added were added to the vector!" << std::endl;
        std::cout << std::endl << "Longest span: " << span2.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span2.shortestSpan() << std::endl << std::endl;
    }
   catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span sp = Span(5);
        sp.addNumber(65);
        sp.addNumber(54533);
        sp.addNumber(25656546);
        sp.addNumber(324);
        sp.addNumber(11);
        sp.addNumber(116);
        sp.addNumber(14531);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "\n\n\n";

        Span sp1 = Span(10000);
        sp1.addSeveralNum(10000);
        std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
