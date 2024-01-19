#include "Bureaucrat.hpp"

// int main(void)
// {
//         Bureaucrat a("a", 1);
//         Bureaucrat b(a);
//         Bureaucrat c("c", 50);

//         c = b;
//         std::cout << a << std::endl;
//         std::cout << b << std::endl;
//         std::cout << c << std::endl;

//         Bureaucrat x("x", 151);

//         std::cout << x << std::endl;

// 		//exception tests

// 		std::cout << "\n\n\n"; 

// 		Bureaucrat d("Andre", 100);
// 		d.displayStatus();
// 		d.incrementGrade();
// 		d.displayStatus();


// 		Bureaucrat e("José", 0);
// 		e.displayStatus();

// 		Bureaucrat f("Manel", 50);
// 		f.displayStatus();
// 		f.decrementGrade();
// 		f.displayStatus();
// }

int main()
{
    Bureaucrat b1("Andre", 3);
    Form form1("contract", 10, 15);

    b1.incrementGrade();
    std::cout << b1 << std::endl;
    b1.decrementGrade();
    std::cout << b1 << std::endl;
    std::cout << form1 << std::endl;
    b1.signForm(form1);
    std::cout << form1 << std::endl;

	std::cout << "\n\n\n";

    
    Bureaucrat b2("Mestre", 100);
    Form form2("declaration", 10, 0);
    b2.incrementGrade();
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
    std::cout << form2 << std::endl;
	b2.signForm(form2);
    std::cout << form2 << std::endl;
}
