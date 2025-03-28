/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:13:13 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/28 12:32:51 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("", 72, 45), _target("") {
    std::cout << "Robotomy Default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target) {
    std::cout << "Robotomy constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) : AForm(other), _target(other._target) {
    std::cout << "Robotomy copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "Robotomy destructor" << std::endl;
}
		
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other) {
    std::cout << "Robotomy assignment operator" << std::endl;
    this->_target = other._target;
    return *this;
}
		
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExc())
		throw GradeTooLowException();

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    
    std::cout << "*LOUD DRILLING NOISES*" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " robotomization failed" << std::endl;
}