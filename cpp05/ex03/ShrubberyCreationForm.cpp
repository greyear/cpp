/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:25:54 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:25:57 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target)
{

}

void ShrubberyCreationForm::specificExecution() const
{
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream file(filename);
    if (!file.is_open())
        throw ShrubberyCreationForm::FileException();
    std::string tree = R"(           ccee88oo
       C8O8O8Q8PoOb o8oo
     dOB69QO8PdUOpugoO9bD
    CgggbU8OU qOp qOdoUOdcb
        6OuU  /p u gcoUodpP
        \\\//  /douUP
            \\\////
            |||/\
            |||\/
            |||||
     .....//||||\....
    )";
    for (int i = 0; i < 3; ++i)
    {
        file << tree << '\n';
    }
	file.close();
}

const char* ShrubberyCreationForm::FileException::what() const noexcept
{
	return ("Couldn't create or open a new file!");
}
