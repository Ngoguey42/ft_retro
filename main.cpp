// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:12:20 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 13:40:48 by ngoguey          ###   ########.fr       //
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

#include <ncurses.h>
#include <unistd.h>

int							main(void)
{
	initscr();
	noecho();


	std::srand(std::time(0));
	Game	*g;

	try
	{
		g = new Game(50, 100);
	}
	catch (std::exception)
	{
		
	}
	Pig	p;

	Pig *p_ptr = &p;
	AObject *a_ptr = &p;


	std::cout << p.getShape() << std::endl;

	std::cout << p << std::endl;

	while (1)
	{
		usleep(500000);
		p.tryMove(*g);
		clear();
		refresh();
		std::cout << p << std::endl;
	}
	
	(void)p;
	(void)p_ptr;
	(void)a_ptr;

	endwin();
	delete g;
	return (0);
}
