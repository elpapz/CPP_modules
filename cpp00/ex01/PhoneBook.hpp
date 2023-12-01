#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	Welcome_Text();
		void Add_Contact();

	private:
		Contact contacts[8];

};


#endif