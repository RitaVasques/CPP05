/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:55:59 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/08 12:56:01 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << std::endl;
    Bureaucrat sarah("Sarah", 42);
    std::cout << "---INITIAL SINGRADE TOO HIGH---" << std::endl;
    try
    {
        Form form_1("Form 1", 0, 120);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "---INITIAL SINGRADE TOO LOW---" << std::endl;
    try
    {
        Form form_2("Form 2", 200, 120);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    std::cout << "---TEST SIGNED GRADE TOO LOW---" << std::endl;
    Form form_3("Form_3", 10, 50);
    std::cout << form_3;
    try
    {
        form_3.beSigned(sarah);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    sarah.signForm(form_3);
    std::cout << std::endl;
    std::cout << "---TEST SIGNED---" << std::endl;
    Form form_4("Form_4", 50, 50);
    std::cout << form_4;
    try
    {
        form_4.beSigned(sarah);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    sarah.signForm(form_4);
    
    return 0;
}