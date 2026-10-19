/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 00:00:00 by Codex             #+#    #+#             */
/*   Updated: 2026/08/17 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

// Factory class able to create concrete forms from their textual names.
class Intern
{
private:
	typedef AForm *(*t_formCreator)(const std::string &target);

	static AForm *createShrubbery(const std::string &target);
	static AForm *createRobotomy(const std::string &target);
	static AForm *createPresidential(const std::string &target);

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif
