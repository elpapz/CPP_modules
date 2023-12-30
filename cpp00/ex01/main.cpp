#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook Phone_list;
	std::string user_input;
	Phone_list.Welcome_Text();
	while (user_input.compare("EXIT") != 0)
	{
		std::cout << "Your command is my wish :) -> ";
		std::getline(std::cin, user_input, '\n');
		if (std::cin.eof())
			break ;
		if (user_input.compare("ADD") == 0)
			Phone_list.Add_Contact();
		else if (user_input.compare("SEARCH") == 0)
			if (!Phone_list.Search_Contact())
				continue;
		std::cin.clear();
	}
}
