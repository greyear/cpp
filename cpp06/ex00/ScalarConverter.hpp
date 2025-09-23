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

//add secondary rule for Makefile

class ScalarConverter
{
	public:
		static convert(const std::string& )
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


typeid() operator to check the data type
*/