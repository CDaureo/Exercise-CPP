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
		
		std::string getName() const;
		bool getSign() const;
		int getGradeSigned() const;
		int getGradeExecuted() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;
		
};
	std::ostream &operator<<(std::ostream &out, const AForm &AForm);


#endif