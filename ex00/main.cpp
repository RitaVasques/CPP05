/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:24:38 by ritavasques       #+#    #+#             */
/*   Updated: 2024/11/14 15:19:46 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "INITIAL TOO HIGH GRADE" << std::endl;
    try 
    {
        Bureaucrat ana("Ana", -42);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "INITIAL TOO LOW GRADE" << std::endl;
    try 
    {
        Bureaucrat ana("Ana", 242);    
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "INCREMENT & DECREMENT" << std::endl;
    Bureaucrat sara("Sara", 42);
    try 
    {
        sara.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << sara;
    std::cout << std::endl;
    try 
    {
        sara.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << sara;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "INCREMENT ERROR" << std::endl;
    Bureaucrat anna("Anna", 1);
    try 
    {
        anna.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;
    
    std::cout << "DECREMENT ERROR" << std::endl;
    Bureaucrat sarah("Sarah", 150);
    try 
    {
        sarah.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << std::endl;

    return (0);
}