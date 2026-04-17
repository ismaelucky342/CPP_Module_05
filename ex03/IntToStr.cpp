/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntToStr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:43:02 by ismherna          #+#    #+#             */
/*   Updated: 2025/12/07 12:32:02 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IntToStr.hpp"

std::string intToStr(int val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}
