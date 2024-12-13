/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:14:25 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/13 14:18:37 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>
#include <cstdint>
#include <string>

int main() {
	// Initialisiere die Datenstruktur
	Data data;
	data.s1 = "Hello";
	data.i1 = 42;
	data.s2 = "Heilbronn";
	data.i2 = 123456;

	// Speicheradresse des ursprünglichen Objekts ausgeben
	std::cout << "Original Data Address: " << &data << std::endl;

	// Serialisieren und Adresse ausgeben
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	// Deserialisieren und Adresse ausgeben
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data Address: " << ptr << std::endl;

	// Gültigkeitsprüfung
	if (ptr == nullptr) {
		std::cerr << "Deserialization failed! Pointer is null." << std::endl;
		return 1;
	}

	// Vergleich der Daten
	if (data.s1 == ptr->s1 && data.i1 == ptr->i1 && data.s2 == ptr->s2 && data.i2 == ptr->i2) {
		std::cout << "Serialization and deserialization succeeded!" << std::endl;
	} else {
		std::cerr << "Mismatch detected between original and deserialized data!" << std::endl;
	}

	// Ausgabe der Daten
	std::cout << "Deserialized data:" << std::endl;
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "i1: " << ptr->i1 << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;
	std::cout << "i2: " << ptr->i2 << std::endl;

	return 0;
}
