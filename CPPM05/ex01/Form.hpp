/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:10:13 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/08/17 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <ostream>
# include <string>

class Bureaucrat;

// Represents a signable form with independent grades for signing and execution.
class Form
{
private:
	const std::string	name;
	bool				sign;
	const int			gradeSigned;
	const int			gradeExecuted;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	Form();
	Form(const std::string &name, int gradeSigned, int gradeExecuted);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string getName() const;
	bool getSign() const;
	int getGradeSigned() const;
	int getGradeExecuted() const;
	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
