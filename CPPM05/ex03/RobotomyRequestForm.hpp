/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:49 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/08/17 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat;

// Concrete form that attempts a 50% chance robotomy on its target.
class RobotomyRequestForm : public AForm
{
private:
	const std::string	target;

public:
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	std::string getTarget() const;
	virtual void execute(const Bureaucrat &executor) const;
};

#endif
