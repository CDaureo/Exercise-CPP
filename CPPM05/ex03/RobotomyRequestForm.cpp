/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:46 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/06 22:35:44 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

const char *RobotomyRequestForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}
const char *RobotomyRequestForm::FormNotGradedException::what() const throw()
{
	return ("Form is not graded");
}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
	if (!this->getSign())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExecuted())
		throw AForm::GradeTooLowException();

	std::cout << "* BZZZZZZZZT *" << std::endl;
	std::cout << "* DRRRRRRRRRR *" << std::endl;
	std::cout << "* VRRRRRRRRRR *" << std::endl;
	std::cout << "* BRRRRRRRRRR *" << std::endl;
	std::cout << "* ZZZZZZZZT *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed" << std::endl;
}