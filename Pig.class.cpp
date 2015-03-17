// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pig.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:59:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 10:56:39 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <Pig.class.hpp>
#include <ft_retro.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Pig::_mobName = "Pig";
Shape const					Pig::_mobShape = Shape(TEST_TAB, TEST_TAB, TEST_TAB);
bool const					Pig::_doesMove = true;
bool const					Pig::_doesShoot = true;

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //

Pig::Pig()
{
	std::cout << "[Pig](main) Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Pig::~Pig()
{
	std::cout << "[Pig]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Pig::getName() const{return Pig::_mobName;}
Shape const					&Pig::getShape() const{return Pig::_mobShape;}
bool						Pig::getDoesMove() const{return Pig::_doesMove;}
bool						Pig::getDoesShoot() const{return Pig::_doesShoot;}
int							Pig::getPosX(void) const{return this->_posX;}
int							Pig::getPosY(void) const{return this->_posY;}
// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						Pig::setPosX(int x){this->_posX = x;}
void						Pig::setPosY(int y){this->_posY = y;}
void						Pig::setPosXY(int x, int y)
{this->_posX = x;this->_posY = y;}

// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
