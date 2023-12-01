#include "Contact.hpp"


Contact::Contact(){}

Contact::~Contact(){}

Contact  Get_Contact_Info()
{
	Contact contact;
	contact.FirstName = contact.Ask_User("Tell us your First Name: ");
	contact.LastName = contact.Ask_User("Tell us your Last Name: ");
	contact.PhoneNumber = contact.Ask_User("Tell us your Phone Number: ");
	contact.NickName = contact.Ask_User("Tell us your Nickname: ");
	contact.DarkestSecret = contact.Ask_User("Tell us your Darkest Secret: ");
	return (contact);
}

std::string	Contact::Ask_User(std::string question)
{
	std::string	user_input;
	std::cout << question;
	std::getline(std::cin, user_input, '\n');
}
