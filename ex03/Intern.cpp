/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:54:21 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/10 11:51:54 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern defaut constructor" << std::endl;
}

Intern::Intern(const Intern & other) {
	std::cout << "Intern copy constructor" << std::endl;
	*this = other;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor" << std::endl;
}

Intern & Intern::operator=(const Intern & other) {
	std::cout << "Inter assignment operator" << std::endl;
	(void)other;
	return *this;
}

static AForm* makeShruebberry(std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm* makePresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string _formName, std::string _target) {
	std::string formNames[] = {
		"presidential pardon", 
		"robotomy request", 
		"shrubbery creation"
	};
	
	AForm *(*forms[])(std::string _target) = {
		&makePresidential,
		&makeRobotomy,
		&makeShruebberry		
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (_formName == formNames[i])
		{
			std::cout << "Intern creates " << _formName << std::endl;
			return (forms[i](_target));
		}
	}
	std::cout << "Intern could not create " << _formName << std::endl;
	return NULL;
}