/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:14:32 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/08 12:49:16 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooLowException::GradeTooLowException() {}
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade to low.";
}

Form::GradeTooHighException::GradeTooHighException() {}
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade to high.";
}

Form::Form(void) : _name(""), _signed(false), _gradeSign(1), _gradeExc(1) {
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExc) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExc(gradeExc) {
    std::cout << "Form constructor" << std::endl;
    if (gradeSign > 150 || gradeExc > 150)
        throw GradeTooLowException();
    if (gradeSign < 1 || gradeExc < 1)
        throw GradeTooHighException();
}

Form::Form(const Form & other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExc(other._gradeExc) {
    std::cout << "Form copy constructor" << std::endl;
}

Form::~Form(void) {
    std::cout << "Form destructor" << std::endl;
}

Form & Form::operator=(const Form & other) {
    std::cout << "Form assignement operator" << std::endl;
    this->_signed = other._signed;
    return *this;
}

std::string Form::getName(void) const {
    return this->_name;
}

bool Form::getSigned(void) const {
    return this->_signed;
}

int Form::getGradeSign(void) const {
    return this->_gradeSign;
}

int Form::getGradeExc(void) const {
    return this->_gradeExc;
}

void Form::beSigned(Bureaucrat & any) {
    if (any.getGrade() <= this->_gradeSign)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & out, const Form & other) {
    out << other.getName() << ". Grade required to sign: " << other.getGradeSign() << ". Grade required to execute: " << other.getGradeExc() << std::endl;
    return out;
}