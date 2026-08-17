/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:47:13 by carlo             #+#    #+#             */
/*   Updated: 2026/07/06 20:39:38 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <ostream>

// Models a bureaucrat whose grade must stay within the [1, 150] range.
class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	// Returns the immutable bureaucrat name.
	std::string getName() const;
	// Returns the current bureaucrat grade.
	int getGrade() const;
	// Promotes the bureaucrat by decreasing the grade value.
	void incrementGrade();
	// Demotes the bureaucrat by increasing the grade value.
	void decrementGrade();

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
