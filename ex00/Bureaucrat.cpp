/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:38:40 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/06 13:45:59 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150) {
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    std::cout << "Bureaucrat constructor" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) {
    std::cout << "Bureaucrat copy constructor" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other) {
    std::cout << "Bureaucrat assigment operator" << std::endl;
    this->_name = other._name;
    if (other._grade > 150)
        throw GradeTooLowException();
    if (other._grade < 1)
        throw GradeTooHighException();
    this->_grade = other._grade;
    return *this;
}

std::string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high, below 1.";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
   
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low, above 150.";
}

void Bureaucrat::incrementGrade(void) {
    if (this->_grade <= 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade >= 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat & other) {
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
    return out;
}