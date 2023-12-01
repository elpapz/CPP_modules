#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook Phone_list;
	std::string user_input;
	//Phone_list.Welcome_Text();
	while (user_input.compare("EXIT") != 0)
	{
		Phone_list.Welcome_Text();
		std::getline(std::cin, user_input, '\n');
		if (user_input.compare("ADD") == 0)
			Phone_list.Add_Contact();
		else if (user_input.compare("SEARCH") == 0)
			Phone_list.Search_Contact();
		std::cin.clear();
	}


}