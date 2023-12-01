#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

void	Welcome_Text()
{
	std::cout	<< "\n\nWelcome to your Phone Book!\n\n";
	std::cout	<< "Please notice that you didin't saved any contact yet, make sure you do that before by entering first the ADD command ;)\n";
	std::cout	<< "\nYou will have 3 possibles commands:\nEXIT: To erase the contacts and exit the PhoneBook\nSEARCH: To search info about a especific contact\nADD: To add a new contact\n\nREMEMBER: You only have room for 8 contacts\n";

}
void	PhoneBook::Add_Contact()
{
	static int i = 0;
	this->contacts[i] = 
}
