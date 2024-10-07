/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:19:04 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/23 13:33:08 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "A_Form.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
	public:
		RobotomyRequestForm(const std::string target);				// Default constructor
		RobotomyRequestForm(const RobotomyRequestForm &ref);				// Copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);		// Copy assignment operator
		~RobotomyRequestForm();								// Destructor

		void	execute(Bureaucrat const & executor) const;
};

#endif