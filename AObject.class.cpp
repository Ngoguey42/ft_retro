// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:33:25 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 08:25:56 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <Shape.class.hpp>
#include <AObject.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
// AObject::AObject()
// {
// 	// std::cout << "[AObject]() Ctor called" << std::endl;
// 	return ;
// }

// AObject::AObject(AObject const &src)
// {
// 	// std::cout << "[AObject](cpy) Ctor called" << std::endl;
// 	(void)src;
// 	return ;
// }

AObject::AObject(char const fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
				 char const fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
	            char const bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH]) :
	Shape(fgChars, fgColors, bgColors), _posX(0), _posY(0)
{
	std::cout << "[AObject](main) Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AObject::~AObject()
{
	std::cout << "[AObject]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
// AObject						&AObject::operator=(AObject const &rhs)
// {
// 	// std::cout << "[AObject]= Overload called" << std::endl;
// 	(void)rhs;
// 	return (*this);
// }

// std::ostream				&operator<<(std::ostream &o, AObject const &rhs)
// {
//	o << rhs.get();
//	return (o);
// }

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
