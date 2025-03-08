/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:02:36 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/08 12:45:18 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROM_HPP
# define FROM_HPP

# include <iostream>

class Bureaucrat;

class Form {
    public:
        Form(void);
        Form(std::string name, int gradeSign, int gradeExc);
        Form(const Form & other);
        ~Form(void);

        Form & operator=(const Form & other);

        std::string getName(void) const;
        bool getSigned(void) const;
        int getGradeSign(void) const;
        int getGradeExc(void) const;
        
        void beSigned(Bureaucrat & any);
        
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
        const std::string _name;
        bool              _signed;
        const int         _gradeSign;
        const int         _gradeExc;
};

std::ostream & operator<<(std::ostream & out, const Form & other);

#endif