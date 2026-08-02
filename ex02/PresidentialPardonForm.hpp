/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:18:57 by ismherna          #+#    #+#             */
/*   Updated: 2025/09/23 13:31:33 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

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