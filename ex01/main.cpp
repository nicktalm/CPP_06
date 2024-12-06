/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:14:25 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/06 16:43:02 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int	main()
{
	Data data;
	data.s1 = "Hello";
	data.i1 = 42;
	data.s2 = "Heilbronn";
	data.i2 = 123456;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "i1: " << ptr->i1 << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;
	std::cout << "i2: " << ptr->i2 << std::endl;

	return 0;
}