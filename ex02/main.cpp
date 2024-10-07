/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:18:51 by ismherna          #+#    #+#             */
/*   Updated: 2024/09/23 13:30:41 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "A_Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	srand(time(NULL));
	try
	{
		Bureaucrat b("Paco", 1);
		ShrubberyCreationForm f1("Shrub Form");
		RobotomyRequestForm f2("Robot Form");
		PresidentialPardonForm f3("Pres Form");

		b.signForm(f1);
		b.executeForm(f1);

		std::cout << f1 << std::endl << std::endl;
		
		b.signForm(f2);
		b.executeForm(f2);
		
		std::cout << f2 << std::endl << std::endl;
		
		b.signForm(f3);
		b.executeForm(f3);
		
		std::cout << f3 << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}