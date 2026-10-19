#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));

	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	AForm *robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *shrubbery = someRandomIntern.makeForm("shrubbery creation", "Garden");
	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Ford");
	AForm *unknown = someRandomIntern.makeForm("coffee request", "Office");

	if (robotomy != NULL)
	{
		boss.signForm(*robotomy);
		boss.executeForm(*robotomy);
		delete robotomy;
	}
	if (shrubbery != NULL)
	{
		boss.signForm(*shrubbery);
		boss.executeForm(*shrubbery);
		delete shrubbery;
	}
	if (pardon != NULL)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}
	delete unknown;
	return (0);
}
