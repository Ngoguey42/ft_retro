// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:33:25 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 12:45:50 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>
#include <Shape.class.hpp>
#include <AObject.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AObject::AObject()
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
std::ostream				&operator<<(std::ostream &o, AObject const &rhs)
{
	std::string			str("");
	std::stringstream	out;
	
	(void)rhs;
	str.append("[");
	str.append(rhs.getName());
	str.append("] {");
	out << rhs.getPosX();
	str.append(out.str());
	str.append(", ");
	out.clear();
	out << rhs.getPosY();
	str.append(out.str());
	str.append("}");
	o << str;
	return (o);
}

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
// * GETTERS *** GETTERS **************************************************** //
int							AObject::getPosX(void) const{return this->_posX;}
int							AObject::getPosY(void) const{return this->_posY;}

// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
