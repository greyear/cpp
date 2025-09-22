/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:24:57 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:24:59 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5, target)
{

}

void PresidentialPardonForm::specificExecution() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
