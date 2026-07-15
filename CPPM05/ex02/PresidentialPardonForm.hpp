/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:59:43 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/07/08 16:37:03 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    	const std::string target;
public:
    class FormNotSignedException : public std::exception
    {
        public: const char *what() const throw();
    };
    class FormNotGradedException : public std::exception
    {
        public: const char *what() const throw();
    };
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();
    std::string getTarget() const;
    virtual void execute(const Bureaucrat &executor) const;
};

#endif

