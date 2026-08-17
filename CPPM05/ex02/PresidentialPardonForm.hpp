/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:43 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/06 21:00:58 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

// Concrete form that grants a presidential pardon to its target.
class PresidentialPardonForm : public AForm
{
private:
	const std::string target;

public:
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	std::string getTarget() const;
	// Pardons the target if the form is signed and the executor grade is sufficient.
	virtual void execute(const Bureaucrat &executor) const;
};

#endif
