// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:33:25 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 12:36:32 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ft_retro.hpp>
#include <AObject.class.hpp>
#include <iostream>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //

// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
AObject::AObject() :
	_posX(0), _posY(0), _deleteObject(false)
{
//	std::cout << "[AObject](main) Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
AObject::~AObject()
{
//	std::cout << "[AObject]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
std::ostream				&operator<<(std::ostream &o, AObject const &rhs)
{	
	o << "[";
	o << rhs.getName();
	o << "] {";
	o << rhs.getPosX();
	o << ", ";
	o << rhs.getPosY();
	o << "}";
	return (o);
}

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
// * GETTERS *** GETTERS **************************************************** //
int							AObject::getPosX(void) const{return this->_posX;}
int							AObject::getPosY(void) const{return this->_posY;}
bool						AObject::getDeleteObject(void) const
	{return this->_deleteObject;}

// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
void						AObject::setPosX(int x){this->_posX = x;}
void						AObject::setPosY(int y){this->_posY = y;}
void						AObject::setDeleteObject(bool state)
{this->_deleteObject = state;}
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						AObject::shootCall(Game &g)
{
	(void)g;
	return ;
}
