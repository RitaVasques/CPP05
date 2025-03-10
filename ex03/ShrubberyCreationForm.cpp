/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:12:30 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/08 17:36:15 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::FileError::FileError() {}
const char* ShrubberyCreationForm::FileError::what() const throw() {
    return "File Error";
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("", 145, 137), _target("") {
    std::cout << "Shruberry Default constructor" << std::cout;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry", 145, 137), _target(target) {
    std::cout << "Shruberry constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other), _target(other._target) {
    std::cout << "Shruberry copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "Shruberry destructor" << std::endl;
}
		
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other) {
    std::cout << "Shruberry assignment operator" << std::endl;
    this->_target = other._target;
    return *this;
}
		
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (this->getSigned() == false)
        throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExc())
        throw GradeTooLowException();

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    std::fstream file;
    file.open(this->_target + "_shruberry", std::fstream::out);
    if (!file)
        throw FileError();
        
    file << "   xx     xx\n";
    file << "  xxxx   xxxx\n";
    file << " xxxxxx xxxxxx\n";
    file << " xxxxxx xxxxxx\n";
    file << "   oo     oo\n";
    file << "   oo     oo\n";
    file << "   oo     oo\n";
    file.close();
}