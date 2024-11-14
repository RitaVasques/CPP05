/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:25:26 by ritavasques       #+#    #+#             */
/*   Updated: 2024/11/14 15:18:05 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//CONTRUCTORS & DESTRUCTOR
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : _name(newName) {
    std::cout << "Constructor called" << std::endl;
    if (newGrade > 150)
        throw GradeTooLowException();
    if (newGrade < 1)
        throw GradeTooHighException();
    this->_grade = newGrade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) {
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Destructor called" << std::endl;
}

//ASSIGNMENT OPERATOR
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other) {
    if (other._grade > 150)
        throw GradeTooLowException();
    if (other._grade < 1)
        throw GradeTooHighException();
    this->_grade = other._grade;
    return (*this);
}

//GETTERS
const std::string Bureaucrat::getName(void) const {
    return (this->_name);
}

int Bureaucrat::getGrade(void) const {
    return (this->_grade);
}

//FUNCTIONS
void Bureaucrat::incrementGrade(void) {
    if (this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade >= 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & other) {
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << "."; 
    return (out);
}