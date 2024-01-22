#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class   ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
		ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(ShrubberyCreationForm const& form);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm&  operator=(ShrubberyCreationForm const& form);
		bool execute(Bureaucrat const& executor) const;
        std::string const&      getTarget() const;
        void                    action() const;
};

#endif