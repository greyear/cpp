/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:19:50 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/03 14:19:52 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <climits>
# include <cstdlib>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define DEF "\x1B[0m"

std::string	getValidatedInput(const std::string& prompt);
int			getValidatedIndex(int maxCount);

#endif
