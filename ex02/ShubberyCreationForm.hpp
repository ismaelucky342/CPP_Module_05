/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShubberyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:19:11 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/23 13:33:39 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm(const std::string target);				// Default constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);				// Copy constructor
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);		// Copy assignment operator
		~ShrubberyCreationForm();								// Destructor

		void	execute(Bureaucrat const & executor) const;
};

#endif