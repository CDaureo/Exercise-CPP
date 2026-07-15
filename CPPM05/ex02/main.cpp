#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 150);
		Bureaucrat signer140("Signer140", 140);
		Bureaucrat executor137("Executor137", 137);
		Bureaucrat carol("Carol", 46);
		Bureaucrat dave("Dave", 25);
		Bureaucrat eric("Eric", 5);

		std::cout << "==== ShrubberyCreationForm tests ====" << std::endl;
		ShrubberyCreationForm shrub("home");
		std::cout << "- Try executing unsigned: \n";
		try { shrub.execute(executor137); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }
		std::cout << "- Sign with a suitable bureaucrat and execute: \n";
		signer140.signAForm(shrub);
		try { shrub.execute(executor137); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }

		std::cout << "\n==== RobotomyRequestForm tests ====" << std::endl;
		RobotomyRequestForm robo("Bender");
		std::cout << "- Sign attempt by too low grade: \n";
		bob.signAForm(robo);
		std::cout << "- Sign by high-rank bureaucrat (works): \n";
		dave.signAForm(robo);
		std::cout << "- Execute with insufficient executor grade: \n";
		try { robo.execute(carol); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }
		std::cout << "- Execute several times (50% success): \n";
		for (int i = 0; i < 5; ++i)
		{
			try { robo.execute(alice); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }
		}

		std::cout << "\n==== PresidentialPardonForm tests ====" << std::endl;
		PresidentialPardonForm pres("Marvin");
		std::cout << "- Execute unsigned: \n";
		try { pres.execute(eric); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }
		std::cout << "- Sign attempts (insufficient then sufficient): \n";
		bob.signAForm(pres);
		dave.signAForm(pres);
		std::cout << "- Execute with insufficient executor (should fail): \n";
		try { pres.execute(dave); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }
		std::cout << "- Execute with sufficient executor (should pardon): \n";
		try { pres.execute(eric); } catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}
	catch (const std::exception &e)
	{
		std::cerr << "Fatal: " << e.what() << std::endl;
	}

	return (0);
}