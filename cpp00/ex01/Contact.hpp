#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>

class Contact
{
	std::string FirstName;
	std::string NickName;
	std::string LastName;
	std::string PhoneNumber;
	std::string DarkestSecret;
	
	public:
		Contact();
		~Contact();
		std::string	Contact::Ask_User(std::string question);
		friend Contact Get_Contact_Info();
		//Contact(std::string FirstName, std::string NickName, std::string LastName, std::string PhoneNumber, std::string DarkestSecret);
		
	
};

#endif
