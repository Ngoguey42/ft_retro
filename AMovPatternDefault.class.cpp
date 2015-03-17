// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternDefault.class.cpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 10:43:59 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 12:34:22 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "AMovPatternDefault.class.hpp"

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AMovPatternDefault::AMovPatternDefault(clock_t moveCD, int moveChancesFactor) :
	_lastMoveTime(std::clock()),
	_moveCD(moveCD),
	_moveChancesFactor(moveChancesFactor)
{
	std::cout << "[AMovPatternDefault]() Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AMovPatternDefault::~AMovPatternDefault()
{
	std::cout << "[AMovPatternDefault]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
int						AMovPatternDefault::tryMove(Game const &g)
{
	int		r;
	
	if (std::clock() >= this->_lastMoveTime &&
		(r = std::rand()) % this->_moveChancesFactor >= 100)
	{
		Shape const	&ref = this->getShape();
		int			x = this->getPosX();
		int			y = this->getPosY();

		if (r % 2)
		{
			if (ref.shapeFits(g, x - 1, y))
				ref.putShape(g, x - 1, y);
			else if (ref.shapeFits(g, x + 1, y))
				ref.putShape(g, x + 1, y);
		}
		else
		{
			if (ref.shapeFits(g, x + 1, y))
				ref.putShape(g, x + 1, y);
			else if (ref.shapeFits(g, x - 1, y))
				ref.putShape(g, x - 1, y);
		}
		this->_lastMoveTime = std::clock();
	}
	return (1);
}
