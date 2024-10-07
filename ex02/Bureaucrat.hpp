/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:18:48 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/23 13:29:19 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include "A_Form.hpp"

class AForm;
class Bureaucrat
{
	private:
		const std::string	_name;
		int				_grade;
	public:
		Bureaucrat(const std::string name, int grade);				// Default constructor
		Bureaucrat(const Bureaucrat &ref);				// Copy constructor
		Bureaucrat &operator=(const Bureaucrat &ref);		// Copy assignment operator
		~Bureaucrat();								// Destructor

		std::string	getName() const;
		int		getGrade() const;

		void		incrementGrade();
		void		decrementGrade();

		void		signForm(AForm &form);

		void		executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream &o, const Bureaucrat &ref);

#endif