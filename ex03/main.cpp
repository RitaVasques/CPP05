/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:55:59 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/10 12:54:44 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::cout << std::endl;
    Bureaucrat sarah("Sarah", 2);
    Intern intern;
    
    std::cout << "--- INTERN PRESIDENTIAL FORM---" << std::endl;
    try
    {
        AForm* form_b = intern.makeForm("presidential pardon", "home");
        if (!form_b)
            return (1);
        std::cout << *form_b << std::endl;
        form_b->beSigned(sarah);
        sarah.signForm(*form_b);
        sarah.executeForm(*form_b);
        
        delete form_b;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "--- INTERN ROBOTOMY FORM---" << std::endl;
    try
    {
        AForm* form_c = intern.makeForm("robotomy request", "home");
        if (!form_c)
            return (1);
        std::cout << *form_c << std::endl;
        form_c->beSigned(sarah);
        sarah.signForm(*form_c);
        sarah.executeForm(*form_c);
        
        delete form_c;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "--- INTERN SHRUBBERY FORM---" << std::endl;
    try
    {
        AForm* form_a = intern.makeForm("shrubbery creation", "home");
        if (!form_a)
            return (1);
        std::cout << *form_a << std::endl;
        form_a->beSigned(sarah);
        sarah.signForm(*form_a);
        sarah.executeForm(*form_a);
        
        delete form_a;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "--- INTER WRONG FORM---" << std::endl;
    try
    {
        AForm* form_d = intern.makeForm("haaalo form", "home");
        if (!form_d)
            return (1);

        delete form_d;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    
    return 0;
}