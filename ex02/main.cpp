/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:55:59 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/08 18:31:38 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << std::endl;
    Bureaucrat sarah("Sarah", 142);
    std::cout << "---SHRUBERRY FORM---" << std::endl;
    try
    {
        ShrubberyCreationForm form_a("home");
        std::cout << form_a << std::endl;
        form_a.beSigned(sarah);
        sarah.signForm(form_a);
        sarah.executeForm(form_a); 
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    Bureaucrat john("John", 42);
    std::cout << "---ROBOTOMY FORM---" << std::endl;
    try
    {
        RobotomyRequestForm form_b("Microwave");
        std::cout << form_b << std::endl;
        form_b.beSigned(john);
        john.signForm(form_b);
        john.executeForm(form_b);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    Bureaucrat hanna("Hanna", 3);
    std::cout << "---PRESIDENTIAL FORM---" << std::endl;
    try
    {
        PresidentialPardonForm form_c("ZigZag");
        std::cout << form_c << std::endl;
        form_c.beSigned(hanna);
        hanna.signForm(form_c);
        hanna.executeForm(form_c);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    
    return 0;
}