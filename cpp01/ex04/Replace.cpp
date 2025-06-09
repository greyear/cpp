/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:47:06 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/09 17:47:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

/*
forbidden: fopen, fclose, fread, fwrite, ...
allowed:
	.find(str, pos) - finds 1st occurence of str starting from pos
	.substr(pos, len) - returns substr starting from pos of length len
	.length()
	.empty() - checks if the string is empty
	+ - concatenates strings

*/

Replace::Replace(const std::string& filename, const std::string& s1,
			const std::string& s2)
{

}

Replace::~Replace()
{

}

bool	Replace::readFile(void)
{
	std::ifstream inputFile(_filename); //in success case InputFile will point on start of the file, have error flags, connection with fd, have internal buffer (but it didn't start reading yet)
	if (!inputFile)
	{
		std::cout << "File can't be open for reading" << std::endl;
		return (false);
	}
	return (true);
}

bool	Replace::writeToFile(void)
{
	std::ofstream outputFile(_filename + ".replace");
	if (!outputFile)
	{
		std::cout << "Replace file can't be created" << std::endl;
		return (false);
	}
	return (true);
}

void	Replace::handleLine(std::string &line)
{
	std::string	buf;
	std::size_t	pos;
	std::size_t	found;

	pos = 0;
	while (found = line.find(_s1, pos) != std::string::npos)
	{
		buf.append(line, pos, found - pos);
		buf.append(_s2);
		pos = found + _s1.length();
	}
	buf.append(line, pos);
	line = buf;
}



/*
*/