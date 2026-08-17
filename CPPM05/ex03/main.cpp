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
		boss.signAForm(*robotomy);
		robotomy->execute(boss);
		delete robotomy;
	}
	if (shrubbery != NULL)
	{
		boss.signAForm(*shrubbery);
		shrubbery->execute(boss);
		delete shrubbery;
	}
	if (pardon != NULL)
	{
		boss.signAForm(*pardon);
		pardon->execute(boss);
		delete pardon;
	}
	delete unknown;
	return (0);
}
