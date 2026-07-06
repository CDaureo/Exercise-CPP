#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 73);
		Bureaucrat carol("Carol", 46);

		std::cout << "[1] Execute without signing" << std::endl;
		RobotomyRequestForm unsignedForm("target-unsigned");
		try
		{
			unsignedForm.execute(alice);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl << "[2] Sign with insufficient grade" << std::endl;
		RobotomyRequestForm signFail("target-sign-fail");
		bob.signAForm(signFail);

		std::cout << std::endl << "[3] Execute with insufficient grade" << std::endl;
		RobotomyRequestForm gradeFail("target-grade-fail");
		alice.signAForm(gradeFail);
		try
		{
			gradeFail.execute(carol);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl << "[4] Successful robotomy" << std::endl;
		RobotomyRequestForm success("target-success");
		alice.signAForm(success);
		success.execute(alice);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}