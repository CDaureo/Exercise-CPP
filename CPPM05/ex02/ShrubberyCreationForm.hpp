/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:26 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/08 16:20:17 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <exception>
#include <string>

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
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
		public: const char *what() const throw();
	};
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	std::string getTarget() const;
	virtual void execute(const Bureaucrat &executor) const;
};

#endif

