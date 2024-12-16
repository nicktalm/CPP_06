/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:14:25 by ntalmon           #+#    #+#             */
/*   Updated: 2024/12/16 13:29:02 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // für srand() und rand()
#include <ctime> // für time()
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int i = rand() % 3;
	std::cout << "Random number: " << i << std::endl;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::bad_cast&) {}
}

int main(void)
{
	srand(static_cast<unsigned>(time(0))); // Seed initialisieren
	for (int i = 0; i < 5; i++)
	{
		Base *p = generate();
		std::cout << "Identifying pointer: ";
		identify(p);
		std::cout << "Identifying reference: ";
		identify(*p);
		delete p;
	}
	return 0;
}