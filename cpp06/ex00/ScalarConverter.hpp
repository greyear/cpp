/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:02:57 by azinchen          #+#    #+#             */
/*   Updated: 2025/09/22 21:02:59 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <regex>
#include <limits>


class ScalarConverter
{
	private:
		static int	afterDot(const std::string& str);
		static void	printChar(char c);
		static void	printInt(int i);
		static void	printFloat(float f);
		static void	printImpossible();
		static void handleChar(const std::string& str);
		static void handleInt(const std::string& str);
		static void handleFloat(const std::string& str);
		static void handleDouble(const std::string& str);
		static void handleSpecial(const std::string& str);
	public:
		ScalarConverter() = delete;
		~ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;

		static void convert(const std::string& str);
};

/*
1) static_cast <new_type> (exp);

used to convert between related types, such as numeric types or pointers
char c = 'a';
int i = static_cast<int>(c);

2) dynamic_cast <new_type> (exp);

returns a null pointer (for pointer conversions) or throws a bad_cast exception (for reference conversions).
Animal* animalPtr = new Dog();
Dog* dogPtr = dynamic_cast<Dog*>(animalPtr) будет не нулл
Cat* catPtr = dynamic_cast<Cat*>(animalPtr) будет нулл!

3) const_cast <new_type> (exp);

allows programmers to temporarily remove the constancy of an object and make modifications
const int n = 5;
const int* ptr = &n;
int* nonConstPtr = const_cast<int*>(ptr);
*nonConstPtr = 10;

4) reinterpret_cast <new_type> (exp);

int n = 10;
int* nptr = &n;
char* charptr = reinterpret_cast<char*>(nptr);


typeid() operator to check the data type
*/