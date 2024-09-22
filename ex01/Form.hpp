/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:32:02 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/22 22:32:04 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int		_gradeToSign;
		const int		_gradeToExecute;
	public:
		Form(const std::string name, int gradeToSign, int gradeToExecute);				// Default constructor
		Form(const Form &ref);				// Copy constructor
		Form &operator=(const Form &ref);		// Copy assignment operator
		~Form();								// Destructor

		void	beSigned(Bureaucrat &b);

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
};

std::ostream &operator<<(std::ostream &o, const Form &ref);

#endif