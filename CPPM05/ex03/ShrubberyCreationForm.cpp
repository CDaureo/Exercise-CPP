/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:52 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/08/17 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Builds the default shrubbery form with subject-defined grades.
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

// Builds a shrubbery form bound to a specific target.
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

const char *ShrubberyCreationForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("Failed to open shrubbery output file");
}

// Writes the ASCII tree into `<target>_shrubbery`.
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	static const char *shrubbery[] = {
		"               ccee88oo",
		"          C8O8O8Q8PoOb o8oo",
		"       dOB69QO8PdUOpugoO9bD",
		"      CgggbU8OU qOp qOdoUOdcb",
		"          6OuU  /p u gcoUodpP",
		"            \\\\//  /douUP",
		"              \\\\////",
		"               |||/\\",
		"               |||\\/",
		"               |||||",
		NULL
	};

	if (!this->getSign())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecuted())
		throw AForm::GradeTooLowException();
	std::ofstream	file((this->target + "_shrubbery").c_str());
	if (!file.is_open())
		throw FileOpenException();
	for (int i = 0; shrubbery[i] != NULL; ++i)
		file << shrubbery[i] << std::endl;
	file << std::endl;
}
