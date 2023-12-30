#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		unsigned int	index;
	public:
		PhoneBook();
		~PhoneBook();
		void	Welcome_Text();
		void 	Add_Contact();
		bool 	Search_Contact();

};
#endif
