#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 140);
		Bureaucrat intern("Intern", 150);

		std::cout << "[1] Execute without signing" << std::endl;
		RobotomyRequestForm unsignedForm("target-unsigned");
		try
		{
			unsignedForm.execute(boss);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl << "[2] Sign with insufficient grade" << std::endl;
		PresidentialPardonForm signFail("target-sign-fail");
		worker.signForm(signFail);

		std::cout << std::endl << "[3] Execute with insufficient grade" << std::endl;
		ShrubberyCreationForm gradeFail("target-grade-fail");
		boss.signForm(gradeFail);
		try
		{
			intern.executeForm(gradeFail);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl << "[4] Successful shrubbery" << std::endl;
		ShrubberyCreationForm shrubbery("garden");
		boss.signForm(shrubbery);
		boss.executeForm(shrubbery);

		std::cout << std::endl << "[5] Successful robotomy" << std::endl;
		RobotomyRequestForm robotomy("Bender");
		boss.signForm(robotomy);
		boss.executeForm(robotomy);

		std::cout << std::endl << "[6] Successful presidential pardon" << std::endl;
		PresidentialPardonForm pardon("Arthur Dent");
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
