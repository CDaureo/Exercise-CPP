/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:48:49 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/06 20:00:47 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), sign(false), gradeSigned(150), gradeExecuted(150)
{
}

Form::Form(const std::string &name, int gradeSigned, int gradeExecuted)
	: name(name), sign(false), gradeSigned(gradeSigned), gradeExecuted(gradeExecuted)
{
	if (gradeExecuted < 1 || gradeSigned < 1)
		throw GradeTooHighException();
	if (gradeExecuted > 150 || gradeSigned > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: name(other.name), sign(other.sign), gradeSigned(other.gradeSigned), gradeExecuted(other.gradeExecuted)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->sign = other.sign;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int Form::getGradeSigned() const
{
	return (this->gradeSigned);
}

int Form::getGradeExecuted() const
{
	return (this->gradeExecuted);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeSigned)
		throw GradeTooLowException();
	this->sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", form signed " << (form.getSign() ? "true" : "false")
		<< ", grade to sign " << form.getGradeSigned()
		<< ", grade to execute " << form.getGradeExecuted() << ".";
	return (out);
}
