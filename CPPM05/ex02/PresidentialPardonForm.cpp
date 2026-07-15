/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:39 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/15 12:02:35 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm ("PresidentialPardonForm",25, 5), target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return(*this);
}
PresidentialPardonForm::~PresidentialPardonForm(){}

const char *PresidentialPardonForm::FormNotGradedException::what() const throw()
{
    return("Form is not Graded");
}
const char *PresidentialPardonForm::FormNotSignedException::what() const throw()
{
    return("Form is not Signed");
}
std::string PresidentialPardonForm::getTarget() const 
{
    return (this->target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecuted())
        throw AForm::GradeTooLowException();

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
