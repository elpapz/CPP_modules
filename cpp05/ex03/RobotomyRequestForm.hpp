#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class   RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
		RobotomyRequestForm();
        RobotomyRequestForm(std::string const& target);
        RobotomyRequestForm(RobotomyRequestForm const& form);
        ~RobotomyRequestForm();
        RobotomyRequestForm&    operator=(RobotomyRequestForm const& form);
		bool execute(Bureaucrat const& executor) const;
        std::string const&      getTarget() const;
};

#endif