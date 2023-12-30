#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0){}

PhoneBook::~PhoneBook(){}

void	PhoneBook::Welcome_Text()
{
	std::cout	<< "\n\nWelcome to your Phone Book!\n\n";
	std::cout	<< "Please notice that you didin't saved any contact yet, make sure you do that before by entering first the ADD command ;)\n";
	std::cout	<< "\nYou will have 3 possibles commands:\nEXIT: To erase the contacts and exit the PhoneBook\nSEARCH: To search info about a especific contact\nADD: To add a new contact\n\nREMEMBER: You only have room for 8 contacts\n";
}
void	PhoneBook::Add_Contact()
{
	if (this->index < 9)
		this->index++;
	this->contacts[this->index - 1].Get_Contact_Info();
}

bool	PhoneBook::Search_Contact()
{
	std::string user_input;
	if (this->index == 0)
	{
		std::cout << "GO SAVE SOME CONTACTS FIRST!!!!!" << std:: endl;
		return false;
	}
	this->contacts[this->index].Choose_Contact();
	for(unsigned int i = 0; this->index > i; i++)
		this->contacts[i].Print_Contacto(this->index);
	std::cout << "Insert the right contact's index please: \n\n";
	std::getline(std::cin, user_input, '\n');
	if (std::cin.eof())
		return false;
	if (user_input.length() != 1)
	{
		std::cout << "\nWrong index!!\nRemember the index range goes from 0 to 8!" << std::endl;
		return false;
	}
	else
		this->contacts->Present_contact(this->index);
	return true;
}
