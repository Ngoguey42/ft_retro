// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/20 08:09:13 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 09:18:36 by wide-aze         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <cstdlib>
#include <Player.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Player::_mobName = "Player";
Shape const					Player::_mobShape =
	Shape(PLAYER_SHAPE, PLAYER_COLOR, DEFAULT_COLOR);
bool const					Player::_doesMove = true;
bool const					Player::_doesShoot = true;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Player::Player() :
	AObject()
{
	std::cout << "[Player](main) Ctor called" << std::endl;
	return ;
}

Player::Player(Player const &src) :
	AObject()
{
	std::cout << "[Player](cpy) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Player::~Player()
{
	std::cout << "[Player]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Player::getName() const{return Player::_mobName;}
Shape const					&Player::getShape() const{return Player::_mobShape;}
bool						Player::getDoesMove() const{return Player::_doesMove;}
bool						Player::getDoesShoot() const{return Player::_doesShoot;}
int							Player::getPosX(void) const{return this->_posX;}
int							Player::getPosY(void) const{return this->_posY;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Player::setPosX(int x){this->_posX = x;}
void						Player::setPosY(int y){this->_posY = y;}
void						Player::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}
void						Player::setDeleteObject(bool b)
{this->_deleteObject = b;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Player::moveCall(Game const &g)
{
	(void)g;
	return ;
}
