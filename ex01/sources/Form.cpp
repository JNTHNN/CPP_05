/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:39:55 by jgasparo          #+#    #+#             */
/*   Updated: 2024/12/22 15:08:22 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(): _name("Default"), _isSigned(false), _gradeToExecute
{
	return;
}

Form::Form(const std::string name): _name(name)
{
	return;
}

Form::~Form()
{
	return;
}
