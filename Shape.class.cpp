// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Shape.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:58:55 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 08:58:33 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstring>
#include <iostream>
#include <Shape.class.hpp>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Shape::Shape(char const fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
			 char const fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
			 char const bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH])
{
	std::cout << "[Shape](main) Ctor called" << std::endl;
	std::memcpy(this->_fgChars, fgChars, sizeof(this->_fgChars));
	std::memcpy(this->_fgColors, fgColors, sizeof(this->_fgColors));
	std::memcpy(this->_bgColors, bgColors, sizeof(this->_bgColors));
	
	return ;
}

Shape::Shape(Shape const &src)
{
	std::cout << "[Shape](cpy) Ctor called" << std::endl;
	std::memcpy(this->_fgChars, src.getFgChars(), sizeof(this->_fgChars));
	std::memcpy(this->_fgColors, src.getFgColors(), sizeof(this->_fgColors));
	std::memcpy(this->_bgColors, src.getBgColors(), sizeof(this->_bgColors));	
	
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Shape::~Shape()
{
	std::cout << "[Shape]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //


std::ostream				&operator<<(std::ostream &o, Shape const &rhs)
{
	o << rhs.shapeToString();
	return (o);
}

// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
int							Shape::getLeftSize(void) const
{return this->_leftSize;}
int							Shape::getRightSize(void) const
{return this->_rightSize;}
int							Shape::getTopSize(void) const
{return this->_topSize;}
int							Shape::getBottomSize(void) const
{return this->_bottomSize;}
char const					**Shape::getFgChars(void) const
{return (char const**)this->_fgChars;}
char const					**Shape::getFgColors(void) const
{return (char const**)this->_fgColors;}
char const					**Shape::getBgColors(void) const
{return (char const**)this->_bgColors;}

// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
// void                        Shape::setShape(Game &g, AObject const &ob) const
// {
// 	(void)g;
// 	(void)ob;
// 	return ;
// }

void						Shape::putShape(Game const &g, int x, int y) const
{
	(void)g;
	(void)x;
	(void)y;
	return ;
}
bool						Shape::shapeFits(Game const &g, int x, int y) const
{
	(void)g;
	(void)x;
	(void)y;
	return (true);
}

std::string					Shape::shapeToString(void) const
{
	std::string str;

	str.append(MAX_SHAPE_WIDTH + 2, '#');
	str.append("\n");
	for (int i = 0; i < MAX_SHAPE_HEIGHT; i++)
	{
		str.append(1, '#');
		for (int j = 0; j < MAX_SHAPE_WIDTH; j++)
		{
			if (this->_fgChars[i][j] == '\0')
				str.append(" ");
			else
				str.append(1, this->_fgChars[i][j]);
		}
		str.append("#\n");
	}
	str.append(MAX_SHAPE_WIDTH + 2, '#');
	return (str);
}
