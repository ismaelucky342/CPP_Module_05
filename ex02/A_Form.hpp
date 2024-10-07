/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_form.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:18:42 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/23 13:29:35 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int		_gradeToSign;
		const int		_gradeToExecute;
	public:
		AForm(const std::string name, int gradeToSign, int gradeToExecute);				// Default constructor
		AForm(const AForm &ref);				// Copy constructor
		AForm &operator=(const AForm &ref);		// Copy assignment operator
		virtual ~AForm();						// Destructor

		void	beSigned(Bureaucrat &b);

		virtual void	execute(Bureaucrat const & executor) const = 0;

		std::string	getName() const;
		bool		getSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &ref);

#endif