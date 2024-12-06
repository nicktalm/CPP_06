/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:06:13 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/06 16:40:22 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}