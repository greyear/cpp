/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:22:11 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:22:12 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target)
{

}

void RobotomyRequestForm::specificExecution() const
{
    std::cout << "drrrr drrrr! *drilling noises*" << std::endl;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 1);

    if (dist(gen) == 1)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed :(" << std::endl;
}
