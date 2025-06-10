/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:46:58 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/09 17:47:01 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace
{
	private:
		std::string		_filename;
		std::string		_s1;
		std::string		_s2;
		std::ifstream	_inputFile;
		std::ofstream	_outputFile;
		bool		checkArgs();
		bool		readFile(void);
		bool		writeToFile(void);
		void		handleLine(std::string &line);
		void		closeFiles();
	public:
		Replace(const std::string& filename, const std::string& s1,
			const std::string& s2);
		~Replace();
		int			replacer(void);
};

#endif
