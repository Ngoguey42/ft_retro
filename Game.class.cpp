// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:10:10 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 09:01:02 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <Pig.class.hpp>
#include <Sheep.class.hpp>
#include <Fizzy.class.hpp>
#include <Snake.class.hpp>
#include <Centipede.class.hpp>
#include <Lombric.class.hpp>
#include <Player.class.hpp>
#include <Missile.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Game::Game(int maxX, int maxY) :
	_maxX(maxX), _maxY(maxY)
{
	std::cout << "[Game]() Ctor called" << std::endl;
	this->_dstFgChars = new std::string[maxY];//try catch
	this->_dstFgColors = new char[maxY * maxX];//try catch
	this->_dstBgColors = new char[maxY * maxX];//try catch
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Game::~Game()
{
	std::cout << "[Game]() Dtor called" << std::endl;
	delete [] this->_dstFgChars;
	delete [] this->_dstFgColors;
	delete [] this->_dstBgColors;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
int							Game::getMaxX(void) const{return this->_maxX;}
int							Game::getMaxY(void) const{return this->_maxY;}
std::string					*Game::getDstFgChars(void) const
{return this->_dstFgChars;}
char						*Game::getDstFgColors(void) const
{return this->_dstFgColors;}
char						*Game::getDstBgColors(void) const
{return this->_dstBgColors;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Game::setFgChar(int x, int y, char c) const
{this->_dstFgChars[y][x] = c;}
void						Game::setFgColor(int x, int y, char c) const
{this->_dstFgColors[y * this->_maxX + x] = c;}
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Game::putImage(void) const
{
	char		prevColorPair = 0;
	const char	*line;
	int			cur_index;
	int			curColorPair;
	
	for (int i = 0; i < this->_maxY; i++)
	{
		line = this->_dstFgChars[i].c_str();
		for (int j = 0; j < this->_maxX; j++)
		{
			cur_index = i * this->_maxX + j;
			curColorPair = (this->_dstBgColors[cur_index] << 4) +
				this->_dstFgColors[cur_index];
			if (curColorPair != prevColorPair)
				attron(COLOR_PAIR(curColorPair));
			printw("%c", line[j]);
			prevColorPair = curColorPair;
		}
	}
	return ;
}

void						Game::putObjects(void) const
{
	std::vector<AObject*>::const_iterator		it;

	for (it = this->_objsVector.begin() ; it < this->_objsVector.end() ; it++)
		(void)(*it)->getShape().putShape(*this, (*it)->getPosX(), (*it)->getPosY());
	return ;
}

static int					randomizeXStart(Shape const &s, int maxX)
{
	maxX -= s.getLeftSize() - s.getRightSize();
	maxX = std::rand() % maxX;
	return (maxX + s.getLeftSize());
} 

void						Game::popSheep(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Sheep(); // try catch
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
		this->_objsVector.push_back(o);
	}
	return ;
}

void						Game::popPig(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Pig(); // try catch
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
		o->setPosY(std::rand() % (this->_maxY / 3) +
				   o->getShape().getTopSize());
		// o->setPosY(std::rand() % 5 + o->getShape().getTopSize());
		this->_objsVector.push_back(o);
		// float t = -3.14159 / 8;
		// float d = 3.14159 / 32;
		
		// this->popMissile(*o, (t += d), CLOCKS_PER_SEC / 45);
		// this->popMissile(*o, (t += d), CLOCKS_PER_SEC / 45);
		// this->popMissile(*o, (t += d), CLOCKS_PER_SEC / 45);
		// this->popMissile(*o, (t += d), CLOCKS_PER_SEC / 45);
		// this->popMissile(*o, (t += d), CLOCKS_PER_SEC / 45);
		// this->popMissile(*o, (t += d), CLOCKS_PER_SEC / 45);
		// this->popMissile(*o, (t += d), CLOCKS_PER_SEC / 45);


// this->popMissile(*o, -3.14159 / 8, CLOCKS_PER_SEC / 45);
		// this->popMissile(*o, +3.14159 / 8, CLOCKS_PER_SEC / 45);
		this->popMissile(*o, 0, CLOCKS_PER_SEC / 45);
	}
	return ;
}

void						Game::popLombric(int count)
{
	AObject		*o;
	
	for (; count > 0; count--)
	{
		o = new Lombric(); // try catch
		Shape const	&s = o->getShape();
		o->setPosX(randomizeXStart(s, this->_maxX / 7 * 5) + this->_maxX / 7);
		o->setPosY(s.getTopSize() - 1);
		this->_objsVector.push_back(o);
	}
	return ;
}

void						Game::popMissile(AObject const &shooter, float angle,
	int movCD)
{
	AObject		*o;

	o = new Missile(angle, shooter.getPosX(), shooter.getPosY() + 1, movCD);
	o->setPosX(shooter.getPosX());
	o->setPosY(shooter.getPosY() + 1);
	this->_objsVector.push_back(o);
	return ;
}

void						Game::popSnake(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Snake(); // try catch
		Shape const	&s = o->getShape();
		o->setPosX(randomizeXStart(s, this->_maxX * 4 / 5) +
				   this->_maxX / 10);
		o->setPosY(s.getTopSize());
		this->_objsVector.push_back(o);
	}
	return ;
}

void						Game::popCentipede(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Centipede(); // try catch
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
		this->_objsVector.push_back(o);
	}
	return ;
}

void						Game::popFizzy(int count)
{
	AObject		*o;

	for (; count > 0; count--)
	{
		o = new Fizzy(); // try catch
		o->setPosX(randomizeXStart(o->getShape(), this->_maxX));
		this->_objsVector.push_back(o);
	}
	return ;
}
