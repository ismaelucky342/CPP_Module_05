/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:18:57 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/23 13:31:33 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "A_Form.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
	public:
		PresidentialPardonForm(const std::string target);				// Default constructor
		PresidentialPardonForm(const PresidentialPardonForm &ref);				// Copy constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);		// Copy assignment operator
		~PresidentialPardonForm();								// Destructor

		void	execute(Bureaucrat const & executor) const;
};

#endif