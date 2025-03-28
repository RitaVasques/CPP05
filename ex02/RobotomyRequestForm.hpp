/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:13:22 by ritavasques       #+#    #+#             */
/*   Updated: 2025/03/28 12:32:20 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# include <cstdlib>

class RobotomyRequestForm : public AForm {
	public:
	  	RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & other);
		~RobotomyRequestForm(void);
		
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);		
		
		void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif