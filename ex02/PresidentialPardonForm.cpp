/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:13:38 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/08 18:28:51 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("", 25, 5), _target("") {
    std::cout << "Presidential Default constructor" << std::cout;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Robotomy", 25, 5), _target(target) {
    std::cout << "Presidential constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) : AForm(other), _target(other._target) {
    std::cout << "Presidential copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "Presidential destructor" << std::endl;
}
		
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other) {
    std::cout << "Presidential assignment operator" << std::endl;
    this->_target = other._target;
    return *this;
}
		
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (this->getSigned() == false)
        throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExc())
        throw GradeTooLowException();

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}