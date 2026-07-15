/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:49 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/08 16:35:04 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;

public:
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
    class FormNotGradedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();
	virtual void execute(const Bureaucrat &executor) const;

	std::string getTarget() const;
};

#endif

