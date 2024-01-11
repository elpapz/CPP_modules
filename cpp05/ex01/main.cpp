#include "Bureaucrat.hpp"

int main(void)
{
        Bureaucrat a("a", 1);
        Bureaucrat b(a);
        Bureaucrat c("c", 50);

        c = b;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        Bureaucrat x("x", 151);

        std::cout << x << std::endl;

		//exception tests

		std::cout << "\n\n\n"; 

		Bureaucrat d("Andre", 100);
		d.displayStatus();
		d.incrementGrade(100);
		d.displayStatus();

		Bureaucrat e("José", 0);
		e.displayStatus();

		Bureaucrat f("Manel", 50);
		f.displayStatus();
		f.decrementGrade(101);
		f.displayStatus();
}
