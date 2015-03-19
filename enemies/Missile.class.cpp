// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Missile.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 11:03:42 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/19 18:22:05 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Missile.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Missile::_mobName = "Missile";
Shape const					Missile::_mobShape =
	Shape(MISSILE_SHAPE, MISSILE_COLOR, DEFAULT_COLOR);
bool const					Missile::_doesMove = false;
bool const					Missile::_doesShoot = false;
clock_t const				Missile::_moveCD = CLOCKS_PER_SEC / 10;
int const					Missile::_moveChancesFactor = 1000;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Missile::Missile() :
	AObject(), AMovPatternSheep(Missile::_moveCD, Missile::_moveChancesFactor)
{
	std::cout << "[Missile](main) Ctor called" << std::endl;
	return ;
}

Missile::Missile(Missile const &src) :
	AObject(), AMovPatternSheep(Missile::_moveCD, Missile::_moveChancesFactor)
{
	std::cout << "[Missile](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Missile::~Missile()
{
	std::cout << "[Missile]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Missile::getName() const{return Missile::_mobName;}
Shape const					&Missile::getShape() const{return Missile::_mobShape;}
bool						Missile::getDoesMove() const{return Missile::_doesMove;}
bool						Missile::getDoesShoot() const{return Missile::_doesShoot;}
int							Missile::getPosX(void) const{return this->_posX;}
int							Missile::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Missile::setPosX(int x){this->_posX = x;}
void						Missile::setPosY(int y){this->_posY = y;}
void						Missile::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Missile::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Missile::moveCall(Game const &g)
{
	this->tryMove(g);
	return ;
}
