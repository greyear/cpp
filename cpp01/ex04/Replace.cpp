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

Replace::Replace(const std::string& filename, const std::string& s1,
			const std::string& s2):
		_filename(filename), _s1(s1), _s2(s2)
{

}

Replace::~Replace()
{

}

bool Replace::checkArgs()
{
	if (_filename.empty())
	{
		std::cout << "Filename shouldn't be empty" << std::endl;
		return (false);
	}
	if (_s1.empty())
	{
		std::cout << "s1 shouldn't be empty" << std::endl;
		return (false);
	}
	return (true);
}

bool	Replace::readFile(void)
{
	_inputFile.open(_filename);
	if (!_inputFile)
	{
		std::cout << "File can't be open for reading" << std::endl;
		return (false);
	}
	return (true);
}

bool	Replace::writeToFile(void)
{
	_outputFile.open(_filename + ".replace");
	if (!_outputFile)
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
	while ((found = line.find(_s1, pos)) != std::string::npos)
	{
		buf.append(line, pos, found - pos);
		buf.append(_s2);
		pos = found + _s1.length();
	}
	buf.append(line, pos);
	line = buf;
}

void	Replace::closeFiles()
{
	if (_inputFile.is_open())
		_inputFile.close();
	if (_outputFile.is_open())
		_outputFile.close();
}

int	Replace::replacer(void)
{
	if (!checkArgs())
		return (1);
	if (!readFile() || !writeToFile())
		return (1);
	std::string	line;
	while (std::getline(_inputFile, line))
	{
		handleLine(line);
		_outputFile << line << "\n";
	}
	closeFiles();
	return (0);
}
