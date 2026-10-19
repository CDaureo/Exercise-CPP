/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:10:13 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/06 20:10:17 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

// Abstract base class for forms that can be signed and later executed.
class AForm
{
	private:
		const std::string name;
		bool sign;
		const int gradeSigned;
		const int gradeExecuted;
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
		
		AForm();
		AForm(const std::string &name, int gradeSigned, int gradeExecuted);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		
		// Returns the immutable form name.
		std::string getName() const;
		// Indicates whether the form has already been signed.
		bool getSign() const;
		// Returns the minimum grade required to sign the form.
		int getGradeSigned() const;
		// Returns the minimum grade required to execute the form.
		int getGradeExecuted() const;
		// Signs the form if the bureaucrat has a sufficiently high grade.
		void beSigned(const Bureaucrat &bureaucrat);
		// Executes the specialized behavior implemented by each derived form.
		virtual void execute(const Bureaucrat &executor) const = 0;
		
};
	std::ostream &operator<<(std::ostream &out, const AForm &AForm);


#endif
