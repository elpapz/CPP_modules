#include "Contact.hpp"
#include <cstdlib>

Contact::Contact(){}

Contact::~Contact(){}

std::string Contact::Ask_User(std::string question)
{
	std::string input;

	while(input.empty())
    {
		std::cout << question << std::flush;
		std::getline(std::cin, input);
		if(!std::cin.good())
		{
            if(std::cin.eof())
                std::exit(130);
			std::cin.clear();
			std::cout << "Invalid input, try a different one." << std::endl;
		}
	}
	return(input);
}

bool	isNum(std::string num)
{
	int	i;

	i = 0;
	while (num[i])
		if (!isdigit(num[i++]))
			return (false);
	return (true);
}

void Contact::Get_Contact_Info()
{
	this->FirstName = Ask_User("Tell us your First Name: ");
	this->LastName = Ask_User("Tell us your Last Name: ");
	this->PhoneNumber = Ask_User("Tell us your Phone Number: ");
	while (isNum(this->PhoneNumber) == false)
	{
		std::cerr << "Invalid Number" << std::endl;
		this->PhoneNumber = Ask_User("Tell us your Phone Number: ");
	}
	this->NickName = Ask_User("Tell us your Nickname: ");
	this->DarkestSecret = Ask_User("Tell us your Darkest Secret: ");
}

void	Contact::Choose_Contact()
{
	std::cout << "|" << std::setw(10) << "index";
    std::cout << "|" << std::setw(10) << "first name";
    std::cout << "|" << std::setw(10) << "last name";
    std::cout << "|" << std::setw(10) << "nickname" << std::endl;
}

std::string teste(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::Print_Contacto(int i)
{
	std::cout << "|" << std::setw(10) << i;
    std::cout << "|" << std::setw(10) << teste(this->FirstName);
    std::cout << "|" << std::setw(10) << teste(this->LastName);
    std::cout << "|" << std::setw(10) << teste(this->NickName);
	std::cout << "\n";
}
void	Contact::Present_contact(int i)
{
	std::cout << "Index: " << i << std::endl;
	std::cout << "\nFirst name: " << this->FirstName << std::endl;
	std::cout << "Last name: " << this->LastName << std::endl;
	std::cout << "Nickname: " << this->NickName << std::endl;
	std::cout << "Phone number: " << this->PhoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->DarkestSecret << std::endl;
	std::cout << std::endl;
}
