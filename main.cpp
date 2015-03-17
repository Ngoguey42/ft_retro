// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:12:20 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 12:46:09 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ft_retro.hpp>
#include <Shape.class.hpp>
#include <AObject.class.hpp>
#include <Pig.class.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

int							main(void)
{
	std::srand(std::time(0));
	// Game	*g;

	// try
	// {
	// 	g = new Game();
	// }
	// catch (std::exception)
	// {
		
	// }
	Pig	p;

	Pig *p_ptr = &p;
	AObject *a_ptr = &p;

	
	std::cout << p << std::endl;
	std::cout << p.getShape() << std::endl;

	

	
	(void)p;
	(void)p_ptr;
	(void)a_ptr;

	// delete g;
	return (0);
}
