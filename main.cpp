// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:12:20 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 11:09:06 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ft_retro.hpp>
#include <Shape.class.hpp>
#include <AObject.class.hpp>
#include <Pig.class.hpp>
#include <Sheep.class.hpp>
#include <Snake.class.hpp>
#include <Centipede.class.hpp>
#include <Lombric.class.hpp>
#include <Fizzy.class.hpp>
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

static void					redraw_events(Game *g, Background *bg)
{
	clear();
	bg->putBackground();
	g->putObjects();
	g->putImage();
	refresh();			
	return ;
}

static void					game_events(Game *g)
{
	std::vector<AObject*>::iterator		it;

	for (it = g->_objsVector.begin(); it < g->_objsVector.end(); it++)
		(*it)->moveCall(*g);
	return ;
}

static void					play(Game *g, Background *bg)
{
	clock_t	lu1_screen = clock();
	clock_t	lu2_events = clock();

	while (1)
	{
		while (clock() - lu2_events > DELTA_REFRESH_EVENTS)
		{
			lu2_events += DELTA_REFRESH_EVENTS;
			game_events(g);
		}
		if (clock() - lu1_screen > DELTA_REFRESH_SCREEN)
		{
			lu1_screen = clock();
			redraw_events(g, bg);
		}
	}
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
		//todo
	}

	Pig p1;
	g->_objsVector.push_back(&p1);
	Pig p2;
	g->_objsVector.push_back(&p2);
	Pig p3;
	g->_objsVector.push_back(&p3);
	Sheep sh1;
	Sheep sh2;
	Sheep sh3;
	g->_objsVector.push_back(&sh1);
	g->_objsVector.push_back(&sh2);
	g->_objsVector.push_back(&sh3);
	Snake sn1;
	Snake sn2;
	Snake sn3;
	g->_objsVector.push_back(&sn1);
	g->_objsVector.push_back(&sn2);
	g->_objsVector.push_back(&sn3);
	Centipede c1;
	Centipede c2;
	Centipede c3;
	g->_objsVector.push_back(&c1);
	g->_objsVector.push_back(&c2);
	g->_objsVector.push_back(&c3);
	Fizzy f1;
	Fizzy f2;
	Fizzy f3;
	g->_objsVector.push_back(&f1);
	g->_objsVector.push_back(&f2);
	g->_objsVector.push_back(&f3);
	Lombric l1;
	Lombric l2;
	Lombric l3;
	g->_objsVector.push_back(&l1);
	g->_objsVector.push_back(&l2);
	g->_objsVector.push_back(&l3);

	play(g, bg);
	endwin();
	delete g;
	delete bg;
	return (0);
}
