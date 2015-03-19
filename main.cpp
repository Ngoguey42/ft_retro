// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:12:20 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 15:39:29 by ngoguey          ###   ########.fr       //
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
#include <Scheduler.class.hpp>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#include <sys/ioctl.h>
#include <ncurses.h>
#include <unistd.h>
/*
player			WHITE   1
missile_player	RED     2

missile			YELLOW  3
ennemies		GREEN   4
ennemies		CYAN    5
ennemies		MAGENTA 6


 */
static void					init_ncurses(void)
{
	initscr();
	start_color();
	noecho();
	init_color(100, 0, 0, 0);
	init_color(101, 100, 100, 100);
	init_pair(0b10000 + 1, COLOR_WHITE, 100);
	init_pair(0b00000 + 1, COLOR_WHITE, 101);
	init_pair(0b10000 + 2, COLOR_RED, 100);
	init_pair(0b00000 + 2, COLOR_RED, 101);
	init_pair(0b10000 + 3, COLOR_YELLOW, 100);
	init_pair(0b00000 + 3, COLOR_YELLOW, 101);
	init_pair(0b10000 + 4, COLOR_GREEN, 100);
	init_pair(0b00000 + 4, COLOR_GREEN, 101);
	init_pair(0b10000 + 5, COLOR_CYAN, 100);
	init_pair(0b00000 + 5, COLOR_CYAN, 101);
	init_pair(0b10000 + 6, COLOR_MAGENTA, 100);
	init_pair(0b00000 + 6, COLOR_MAGENTA, 101);
	
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

static void					game_events(Game &g, Scheduler &s)
{
	AObject								*ob;

	for (int i = 0; i < (int)g._objsVector.size();)
	{
		ob = g._objsVector.at(i);
		if (ob->getDeleteObject())
		{
			g._objsVector.erase(g._objsVector.begin() + i);
			delete ob;
		}
		else
		{
			ob->moveCall(g);
			//shootCall (tryShoot)
			i++;
		}
	}
	s.tryNewWave(g);
	return ;
}

static void					play(Game *g, Background *bg, Scheduler &s)
{
	clock_t	lu1_screen = clock();
	clock_t	lu2_events = clock();

	while (1)
	{
		while (clock() - lu2_events > DELTA_REFRESH_EVENTS)
		{
			lu2_events += DELTA_REFRESH_EVENTS;
			game_events(*g, s);
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
	Scheduler		s(0, CLOCKS_PER_SEC);
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

	// Pig p1;
	// g->_objsVector.push_back(&p1);
	// Pig p2;
	// g->_objsVector.push_back(&p2);
	// Pig p3;
	// g->_objsVector.push_back(&p3);
	// Sheep sh1;
	// Sheep sh2;
	// Sheep sh3;
	// g->_objsVector.push_back(&sh1);
	// g->_objsVector.push_back(&sh2);
	// g->_objsVector.push_back(&sh3);
	// Snake sn1;
	// Snake sn2;
	// Snake sn3;
	// g->_objsVector.push_back(&sn1);
	// g->_objsVector.push_back(&sn2);
	// g->_objsVector.push_back(&sn3);

	play(g, bg, s);
	endwin();
	delete g;
	delete bg;
	return (0);
}
