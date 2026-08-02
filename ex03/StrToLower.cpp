/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StrToLower.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:55:43 by ismherna          #+#    #+#             */
/*   Updated: 2025/12/07 14:55:19 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StrToLower.hpp"

std::string strToLower(std::string src)
{
	for (size_t i = 0 ; i < src.size() ; ++i)
		src[i] = std::tolower(src[i]);
	return src;
}