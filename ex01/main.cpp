/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:14:25 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/11 16:19:29 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

// int	main()
// {
// 	Data data;
// 	data.s1 = "Hello";
// 	data.i1 = 42;
// 	data.s2 = "Heilbronn";
// 	data.i2 = 123456;

// 	uintptr_t raw = Serializer::serialize(&data);
// 	Data *ptr = Serializer::deserialize(raw);
	
// 	std::cout << "s1: " << ptr->s1 << std::endl;
// 	std::cout << "i1: " << ptr->i1 << std::endl;
// 	std::cout << "s2: " << ptr->s2 << std::endl;
// 	std::cout << "i2: " << ptr->i2 << std::endl;

// 	return 0;
// }

int main()
{
	// Initialisiere die Datenstruktur
	Data data;
	data.s1 = "Hello";
	data.i1 = 42;
	data.s2 = "Heilbronn";
	data.i2 = 123456;

	// Serialisieren und ausgeben
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	// Deserialisieren
	Data *ptr = Serializer::deserialize(raw);

	// Gültigkeitsprüfung
	if (ptr == nullptr)
	{
		std::cerr << "Deserialization failed! Pointer is null." << std::endl;
		return 1;
	}

	// Vergleich der Daten
	if (data.s1 == ptr->s1 && data.i1 == ptr->i1 && data.s2 == ptr->s2 && data.i2 == ptr->i2)
	{
		std::cout << "Serialization and deserialization succeeded!" << std::endl;
	}
	else
	{
		std::cerr << "Mismatch detected between original and deserialized data!" << std::endl;
	}

	// Ausgabe der Daten
	std::cout << "Deserialized data:" << std::endl;
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "i1: " << ptr->i1 << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;
	std::cout << "i2: " << ptr->i2 << std::endl;

	// Test für null-Zeiger (optional)
	uintptr_t invalidRaw = Serializer::serialize(nullptr);
	Data *invalidPtr = Serializer::deserialize(invalidRaw);

	if (invalidPtr == nullptr)
	{
		std::cout << "Deserialization correctly handled a null pointer." << std::endl;
	}
	else
	{
		std::cerr << "Error: Null pointer was not handled properly!" << std::endl;
	}

	return 0;
}