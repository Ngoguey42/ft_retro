// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:10:10 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 12:02:01 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include <iostream>
#include <ncurses.h>
#include <Pig.class.hpp>
#include <Sheep.class.hpp>

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
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Game::putImage(void) const
{
	char		prevBgColor = 0;
	const char	*line;
	int			cur_index;

	
	for (int i = 0; i < this->_maxY; i++)
	{
		line = this->_dstFgChars[i].c_str();
		for (int j = 0; j < this->_maxX; j++)
		{
			cur_index = i * this->_maxX + j;
			if (this->_dstBgColors[cur_index] != prevBgColor)
				attron(COLOR_PAIR(this->_dstBgColors[cur_index]));
			printw("%c", line[j]);
			prevBgColor = this->_dstBgColors[cur_index];
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
		o->setPosX = randomizeXStart(o->getShape(), g->_maxX);
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
		this->_objsVector.push_back(o);
	}
	return ;
}
