#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 2);
		Bureaucrat bob("Bob", 75);
		Form contract("Contract", 50, 20);
		Form topSecret("TopSecret", 1, 1);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << contract << std::endl;
		std::cout << topSecret << std::endl;

		bob.signForm(contract);
		alice.signForm(contract);
		alice.signForm(topSecret);
		std::cout << contract << std::endl;
		std::cout << topSecret << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form invalid("Invalid", 0, 200);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}