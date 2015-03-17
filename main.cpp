// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:12:20 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 08:14:03 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ft_retro.hpp>
#include <Shape.class.hpp>
#include <AObject.class.hpp>
#include <Pig.class.hpp>
#include <iostream>
#include <stdexcept>

int							main(void)
{
	Game	*g;

	try
	{
		g = new Game();
	}
	catch (std::exception)
	{
		
	}
	Pig	p;
	
	Shape *s = &p;
	// Shape s(TEST_TAB, TEST_TAB, TEST_TAB);

	std::cout << *s << std::endl;
	
	(void)p;

	delete g;
	return (0);
}
