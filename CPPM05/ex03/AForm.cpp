/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:48:49 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/06 20:00:47 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), sign(false), gradeSigned(150), gradeExecuted(150)
{
}

AForm::AForm(const std::string &name, int gradeSigned, int gradeExecuted)
	: name(name), sign(false), gradeSigned(gradeSigned), gradeExecuted(gradeExecuted)
{
	if (gradeExecuted < 1 || gradeSigned < 1)
		throw GradeTooHighException();
	if (gradeExecuted > 150 || gradeSigned > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name), sign(other.sign), gradeSigned(other.gradeSigned), gradeExecuted(other.gradeExecuted)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->sign = other.sign;
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (this->sign);
}

int AForm::getGradeSigned() const
{
	return (this->gradeSigned);
}

int AForm::getGradeExecuted() const
{
	return (this->gradeExecuted);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeSigned)
		throw GradeTooLowException();
	this->sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << ", AForm signed ";
	if (AForm.getSign())
		out << "true";
	else
		out << "false";
	out << ", grade to sign " << AForm.getGradeSigned()
		<< ", grade to execute " << AForm.getGradeExecuted() << ".";
	return (out);
}
