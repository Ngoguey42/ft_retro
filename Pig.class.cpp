// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pig.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:59:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 08:31:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include <Pig.class.hpp>
#include <ft_retro.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
std::string const			Pig::_mobName = "Pig";
bool const					Pig::_doesMove = true;
bool const					Pig::_doesShoot = true;
char const					Pig::_fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH] =
	TEST_TAB2;
char const					Pig::_fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH] =
	TEST_TAB2;
char const					Pig::_bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH] =
	TEST_TAB2;
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
// Pig::Pig(Pig const &src)
// {
// 	// std::cout << "[Pig](cpy) Ctor called" << std::endl;
// 	(void)src;
// 	return ;
// }

Pig::Pig() :
	AObject(Pig::_fgChars, Pig::_fgColors, Pig::_bgColors)
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
// Pig							&Pig::operator=(Pig const &rhs)
// {
// 	// std::cout << "[Pig]= Overload called" << std::endl;
// 	(void)rhs;
// 	return (*this);
// }

// std::ostream				&operator<<(std::ostream &o, Pig const &rhs)
// {
//	o << rhs.get();
//	return (o);
// }

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
std::string const			&Pig::getName() const{return Pig::_mobName;}
bool						Pig::getDoesMove() const{return Pig::_doesMove;}
bool						Pig::getDoesShoot() const{return Pig::_doesShoot;}
// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
