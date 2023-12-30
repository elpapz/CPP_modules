#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string FirstName;
		std::string NickName;
		std::string LastName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		Contact();
		~Contact();
		std::string	Ask_User(std::string question);
		void Get_Contact_Info();
		void	Print_Contacto(int i);
		void	Present_contact(int i);
		void	Choose_Contact();

};

#endif
