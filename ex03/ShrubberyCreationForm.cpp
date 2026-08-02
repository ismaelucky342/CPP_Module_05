/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 10:19:21 by ismherna          #+#    #+#             */
/*   Updated: 2025/12/07 15:11:34 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int writeTruncFile(ShrubberyCreationForm const & src)
{
	std::string filename = src.getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str(), std::ios::trunc);
	if (!outFile) {
		std::cout << "Error to open file: "<< filename << std::endl;
		return 1;
	}
	outFile << "     &\n";
	outFile << "    &&&\n";
	outFile << "   &&&&&\n";
	outFile << "  &&&&&&&\n";
	outFile << " &&&&&&&&&\n";
	outFile << "&&&&&&&&&&&\n";
	outFile << "     |||\n";
	outFile << "     |||\n";
	outFile.close();
	return 0;
}

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation Form", 145, 137) , _target(""){
	std::cout << "[BUilder] Shrubbery Creation Form with target "<< this->_target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[Destroyed] Shrubbery Creation Form"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery Creation Form", 145, 137), _target(target){
	std::cout << "[BUilder] Shrubbery Creation Form with target "<< this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
Form(src.getName(), src.getSignGrade(), src.getExecGrade()),
_target(src.getTarget())
{
	std::cout << "[Copy] Shrubbery Creation Form"<< std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	std::cout << "[Assignment] Shrubbery Creation Form called to assignment " << src.getName() << std::endl;
	if (this == &src)
		return (*this);
	this->_target = src.getTarget();
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & src) const {
	if (!this->getIsSigned())
		throw Form::FormNotSignedException();
	this->verifyGrade(src.getGrade(), this->getExecGrade(), 1);
	writeTruncFile(*this);
	std::cout << " File " << this->getTarget() << "_shrubbery created"<< std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}


std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a) {
	if (!a)
		return (o);
	o << a->getName() 
	<< ", form signed: " << a->getIsSigned() 
	<< ", form sign grade " << a->getSignGrade() 
	<< ", form exec grade " << a->getExecGrade()
	<< ", form target "<< a->getTarget() << std::endl;
	return (o);
}
