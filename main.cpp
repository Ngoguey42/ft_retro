// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:12:20 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 09:31:44 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ft_retro.hpp>
#include <Shape.class.hpp>
#include <AObject.class.hpp>
#include <Pig.class.hpp>
#include <Sheep.class.hpp>
#include <Background.class.hpp>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#include <sys/ioctl.h>
#include <ncurses.h>
#include <unistd.h>

static void					init_ncurses(void)
{
	initscr();
	start_color();
	noecho();
	init_color(100, 0, 0, 0);
	init_color(101, 100, 100, 100);
	init_pair(1, COLOR_RED, 100);
	init_pair(2, COLOR_RED, 101);
	return ;
}

int							main(void)
{
	Game			*g = NULL;
	Background		*bg = NULL;
	struct winsize	w;

	init_ncurses();
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	std::srand(std::time(0));
	try
	{
		g = new Game(w.ws_col, w.ws_row);
		bg = new Background(w.ws_col, w.ws_row, *g);
		std::cout << w.ws_col << std::endl;
		std::cout << w.ws_row << std::endl;
	}
	catch (std::exception)
	{
		
	}
	Pig	p;
	Pig *p_ptr = &p;
	AObject *a_ptr = &p;











	Pig p1;
	g->_objsVector.push_back(&p1);





	






	Pig p2;
	g->_objsVector.push_back(&p2);
	Pig p3;
	g->_objsVector.push_back(&p3);

	Sheep s1;
	Sheep s2;
	Sheep s3;
	g->_objsVector.push_back(&s1);
	g->_objsVector.push_back(&s2);
	g->_objsVector.push_back(&s3);
	
	clock_t	lu1_screen = clock();
	clock_t	lu2_events = clock();

	// std::cout << "test" << std::endl;
		// return (0);	
	std::vector<AObject*>::iterator		it;
	while (1)
	{

		while (clock() - lu2_events > DELTA_REFRESH_EVENTS)
		{
			lu2_events += DELTA_REFRESH_EVENTS;
			for (it = g->_objsVector.begin(); it < g->_objsVector.end(); it++)
				(*it)->moveCall(*g);
		}
		if (clock() - lu1_screen > DELTA_REFRESH_SCREEN)
		{
			lu1_screen = clock();
			clear();
			bg->putBackground();
			g->putObjects();
			g->putImage();
			refresh();
		}
		// usleep(41667);
	}
	(void)bg;
	(void)p;
	(void)p_ptr;
	(void)a_ptr;
	(void)lu2_events;
	(void)lu1_screen;

	endwin();
	delete g;
	delete bg;
	return (0);
}
