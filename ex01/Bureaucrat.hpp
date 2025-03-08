/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:32:23 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/06 16:28:32 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Form;

class Bureaucrat {
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat & other);
        ~Bureaucrat(void);

        Bureaucrat & operator=(const Bureaucrat & other);

        std::string getName(void) const;
        int getGrade(void) const;

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(Form & any);

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                GradeTooHighException();
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                GradeTooLowException();
                const char *what() const throw();
        };
        
    private:
        std::string _name;
        int         _grade;
};

// Overload
std::ostream & operator<<(std::ostream & out, const Bureaucrat & other);

#endif