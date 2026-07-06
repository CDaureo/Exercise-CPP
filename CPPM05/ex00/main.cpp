#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat john("John", 42);
		std::cout << john << std::endl;
		john.incrementGrade();
		std::cout << john << std::endl;
		john.decrementGrade();
		john.decrementGrade();
		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bad("Bad", 0);
		std::cout << bad << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bad("Bad", 151);
		std::cout << bad << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}