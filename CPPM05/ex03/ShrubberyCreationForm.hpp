/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:59:49 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/11/16 13:59:18 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <string>
# include "AForm.hpp"

class Bureaucrat;

// Concrete form that writes an ASCII tree into a target file.
class ShrubberyCreationForm : public AForm
{
private:
	const std::string	target;

public:
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class FileOpenException : public std::exception
	{
	public:
		const char *what() const throw();
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
