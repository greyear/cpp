/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:22:57 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 15:22:59 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm() = delete;
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other) = default;
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
        ~ShrubberyCreationForm() override = default;

        void specificExecution() const override;

        class FileException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

