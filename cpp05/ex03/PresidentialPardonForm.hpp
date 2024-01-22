#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
		PresidentialPardonForm();
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(PresidentialPardonForm const& form);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(PresidentialPardonForm const& form);
		bool execute(Bureaucrat const& executor) const;
        std::string const&      getTarget() const;
};

#endif
