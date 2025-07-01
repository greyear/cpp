/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:04:37 by azinchen          #+#    #+#             */
/*   Updated: 2025/06/30 20:04:39 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria() = delete;
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		
		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; //AMateria* newIce = ice.clone(); // создает новый Ice
		virtual void use(ICharacter& target) = 0;
};

#endif

/*
Класс AMateria (абстрактный класс — базовый для всех материй)
	Классы Ice и Cure (наследники AMateria)
Интерфейс ICharacter: Это интерфейс для персонажей. Персонаж должен уметь:
	Получить свое имя — getName().
	Надеть материю в инвентарь — equip(AMateria*).
	Снять материю — unequip(int idx) (❗️при этом НЕ удалять ее).
	Использовать материю по индексу на цель — use(int idx, ICharacter&).
Класс Character (реализация ICharacter):
Интерфейс IMateriaSource: Источник знаний о материях.
Имеет 2 функции:
	learnMateria(AMateria*) — запоминает шаблон материи (до 4 штук).
	createMateria(std::string const & type) — создает копию материи с указанным типом (если знает её, иначе вернет nullptr).
Класс MateriaSource (реализация IMateriaSource)

Что должно быть в интерфейсе: Только чисто виртуальные методы (= 0).
Интерфейс говорит: "все, кто меня реализует, должны уметь вот это..."
Конкретный класс решает: "а вот как именно это работает — решаю я!"
*/