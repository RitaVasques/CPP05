/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:02:36 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/10 12:53:14 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFROM_HPP
# define AFROM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
    public:
        AForm(void);
        AForm(std::string name, int gradeSign, int gradeExc);
        AForm(const AForm & other);
        virtual ~AForm(void);

        AForm & operator=(const AForm & other);

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

        class FormNotSignedException : public std::exception {
            public:
                FormNotSignedException();
                const char* what() const throw();
        };

        virtual void execute(Bureaucrat const & executor) const = 0;
        
    private:
        const std::string _name;
        bool              _signed;
        const int         _gradeSign;
        const int         _gradeExc;
};

std::ostream & operator<<(std::ostream & out, const AForm & other);

#endif