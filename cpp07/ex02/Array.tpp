/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:25:24 by azinchen          #+#    #+#             */
/*   Updated: 2025/10/22 13:25:26 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array(): _size(0), _array(nullptr)
{

}

template<typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	if (n > 0)
		_array = new T[n]();
	else
		_array = nullptr;
}

template<typename T>
Array<T>::Array(const Array<T>& other): _size(other._size)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
		{
			_array[i] = other._array[i];
		}
	}
	else
		_array = nullptr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
			{
				_array[i] = other._array[i];
			}
		}
		else
			_array = nullptr;
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::exception();
	return (_array[i]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::exception();
	return (_array[i]);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
