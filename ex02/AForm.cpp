/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:14:32 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/10 12:53:43 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::GradeTooLowException::GradeTooLowException() {}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade to low.";
}

AForm::GradeTooHighException::GradeTooHighException() {}
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade to high.";
}

AForm::FormNotSignedException::FormNotSignedException() {}
const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

AForm::AForm(void) : _name(""), _signed(false), _gradeSign(1), _gradeExc(1) {
    std::cout << "Form default constructor" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExc) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExc(gradeExc) {
    std::cout << "Form constructor" << std::endl;
    if (gradeSign > 150 || gradeExc > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExc < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm & other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExc(other._gradeExc) {
    std::cout << "Form copy constructor" << std::endl;
}

AForm::~AForm(void) {
    std::cout << "Form destructor" << std::endl;
}

AForm & AForm::operator=(const AForm & other) {
    std::cout << "Form assignement operator" << std::endl;
    this->_signed = other._signed;
    return *this;
}

std::string AForm::getName(void) const {
    return this->_name;
}

bool AForm::getSigned(void) const {
    return this->_signed;
}

int AForm::getGradeSign(void) const {
    return this->_gradeSign;
}

int AForm::getGradeExc(void) const {
    return this->_gradeExc;
}

void AForm::beSigned(Bureaucrat & any) {
    if (any.getGrade() <= this->_gradeSign)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & out, const AForm & other) {
    out << other.getName() << ". Grade required to sign: " << other.getGradeSign() << ". Grade required to execute: " << other.getGradeExc() << std::endl;
    return out;
}