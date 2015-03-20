// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/20 08:09:13 by wide-aze          #+#    #+#             //
//   Updated: 2015/03/20 15:33:23 by wide-aze         ###   ########.fr       //
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

Player::Player(Game &g) :
	AObject(), _game(g)
{
	this->setPosX(g.getMaxX() / 2);
	this->setPosY(g.getMaxY() - 5);
	// std::cout << "[Player](main) Ctor called" << std::endl;
	return ;
}

// Player::Player(Player const &src) :
	// AObject(), _game(src.getGame())
// {
	// (void)src;
	// return ;
// }

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Player::~Player()
{
	// std::cout << "[Player]() Dtor called" << std::endl;
	this->_game.leave_game("You died...");
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
Game                        &Player::getGame(void){return this->_game;}

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

void						Player::moveEvent(Game const &g, int x, int y)
{
	if (this->_posX + x > 4 && this->_posX + x + 6 <= g.getMaxX()
		&& this->_posY + y > 0 && this->_posY + y + 4 <= g.getMaxY())
	{
		this->_posX += 2 * x;
		this->_posY += y;
	}
	else if (this->_posX + x > 3 && this->_posX + x + 5 <= g.getMaxX()
		&& this->_posY + y > 0 && this->_posY + y + 4 <= g.getMaxY())
	{
		this->_posX += x;
		this->_posY += y;
	}
	return ;
}
