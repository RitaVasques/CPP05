/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:24:58 by ritavasques       #+#    #+#             */
/*   Updated: 2024/11/14 15:17:18 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

// _grade between 1(highest) and 150(lowest)
class Bureaucrat {
  private:
    const std::string   _name;
    int                 _grade;
  public:
    //constructors & destructors
    Bureaucrat(void);
    Bureaucrat(std::string newName, int newGrade);
    Bureaucrat(Bureaucrat const & other);
    ~Bureaucrat(void);
    
    //assignment operator
    Bureaucrat & operator=(Bureaucrat const & other);
    
    //getters
    const std::string getName(void) const;
    int getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);

    //nested exception classes
    class GradeTooHighException : public std::exception
    {
        public:
            GradeTooHighException() throw() {}
            virtual const char *what() const throw() 
            {
                return "Grade bellow 1, too high";
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException() throw() {}
            virtual const char *what() const throw()
            {
                return "Grade above 150, too low";
            }
    };
    
};

//<< overload
std::ostream & operator<<(std::ostream & out, Bureaucrat const & other);

#endif