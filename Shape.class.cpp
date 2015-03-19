// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Shape.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:58:55 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 07:28:18 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <Shape.class.hpp>
#include <cstring>
#include <iostream>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
static void					get_sizes(
	char const fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
	int sizes[4])
{
	sizes[0] = -1;
	for (int i = 0; i < MAX_SHAPE_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_SHAPE_WIDTH; j++)
		{
			if (fgChars[i][j] != '\0')
			{
				if (sizes[0] == -1)
				{
					sizes[0] = i;
					sizes[2] = j;
					sizes[3] = j;
					
				}
				sizes[1] = i;
				if (j < sizes[2])
					sizes[2] = j;
				if (j > sizes[3])
					sizes[3] = j;
			}
		}
	}
	return ;
}


Shape::Shape(char const fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
			 char const fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
			 char const bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH])
{
	int		sizes[4];

	std::cout << "[Shape](main) Ctor called" << std::endl;
	std::memcpy(this->_fgChars, fgChars, sizeof(this->_fgChars));
	std::memcpy(this->_fgColors, fgColors, sizeof(this->_fgColors));
	std::memcpy(this->_bgColors, bgColors, sizeof(this->_bgColors));
	get_sizes(fgChars, sizes);
	this->_topSize = MID_SHAPE_INDEX - sizes[0];
	this->_bottomSize = sizes[1] - MID_SHAPE_INDEX;
	this->_leftSize = MID_SHAPE_INDEX - sizes[2];
	this->_rightSize = sizes[3] - MID_SHAPE_INDEX;
	this->_minYStr = MID_SHAPE_INDEX - this->_topSize;
	this->_maxYStr = MID_SHAPE_INDEX + this->_bottomSize;
	this->_minXStr = MID_SHAPE_INDEX - this->_leftSize;
	this->_maxXStr = MID_SHAPE_INDEX + this->_rightSize;
	std::cout << *this << std::endl;
	return ;
}

Shape::Shape(Shape const &src)
{
	std::cout << "[Shape](cpy) Ctor called" << std::endl;
	std::memcpy(this->_fgChars, src.getFgChars(), sizeof(this->_fgChars));
	std::memcpy(this->_fgColors, src.getFgColors(), sizeof(this->_fgColors));
	std::memcpy(this->_bgColors, src.getBgColors(), sizeof(this->_bgColors));	
	this->_topSize = src.getTopSize();
	this->_bottomSize = src.getBottomSize();
	this->_leftSize = src.getLeftSize();
	this->_rightSize = src.getRightSize();
	this->_minYStr = MID_SHAPE_INDEX - this->_topSize;
	this->_maxYStr = MID_SHAPE_INDEX + this->_bottomSize;
	this->_minXStr = MID_SHAPE_INDEX - this->_leftSize;
	this->_maxXStr = MID_SHAPE_INDEX + this->_rightSize;
	std::cout << *this << std::endl;
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
bool						Shape::putShape(Game const &g, int posX, int posY)
	const
{
	int		yStr = this->_minYStr;
	int		yScreen = posY - this->_topSize;
	int		minXStr = this->_minXStr;
	int		minXScreen = posX - this->_leftSize;
	int		xStr;
	int		xScreen;
	bool	drawn = false;
	
	if (yScreen < 0)
	{
		yStr -= yScreen;
		yScreen = 0;
	}
	if (minXScreen < 0)
	{
		minXStr -= minXScreen;
		minXScreen = 0;
	}
	for (;yStr <= this->_maxYStr && yScreen < g.getMaxY();yStr++, yScreen++)
	{
		xStr = minXStr;
		xScreen = minXScreen;
		for (;xStr <= this->_maxXStr && xScreen < g.getMaxX();xStr++, xScreen++)
		{
			if (this->_fgChars[yStr][xStr] != '\0')
			{
				g.setFgChar(xScreen, yScreen, this->_fgChars[yStr][xStr]);
				drawn = true;
			}
		}
	}
	return (drawn);
}
bool						Shape::shapeFits(Game const &g, int x, int y) const
{
	if (x < 0 || y < 0 || x >= g.getMaxX() || y >= g.getMaxY())
		return (false);
	return (true);
}

std::string					Shape::shapeToString(void) const
{
	std::string		str;

	str += "top(";
	str += (char)('0' + (this->_topSize / 10));
	str += (char)('0' + (this->_topSize % 10));
	str += ") ";
	str += "bot(";
	str += (char)('0' + (this->_bottomSize / 10));
	str += (char)('0' + (this->_bottomSize % 10));
	str += ") ";
	str += "left(";
	str += (char)('0' + (this->_leftSize / 10));
	str += (char)('0' + (this->_leftSize % 10));
	str += ") ";
	str += "right(";
	str += (char)('0' + (this->_rightSize / 10));
	str += (char)('0' + (this->_rightSize % 10));
	str += ") \n";
	
	str += "x(";
	str += (char)('0' + (this->_minXStr / 10));
	str += (char)('0' + (this->_minXStr % 10));
	str += '-';
	str += (char)('0' + (this->_maxXStr / 10));
	str += (char)('0' + (this->_maxXStr % 10));
	str += ") y(";
	str += (char)('0' + (this->_minYStr / 10));
	str += (char)('0' + (this->_minYStr % 10));
	str += '-';
	str += (char)('0' + (this->_maxYStr / 10));
	str += (char)('0' + (this->_maxYStr % 10));
	str += ")\n";

	str.append("/");
	for (int i = 0; i < MAX_SHAPE_WIDTH; i++)
		str += (char)('0' + (i % 10));
	str += "\\\n";
	for (int i = 0; i < MAX_SHAPE_HEIGHT; i++)
	{
		str += (char)('0' + (i % 10));
		for (int j = 0; j < MAX_SHAPE_WIDTH; j++)
		{
			if (this->_fgChars[i][j] == '\0')
				str.append(" ");
			else
				str.append(1, this->_fgChars[i][j]);
		}
		str.append("I\n");
	}
	str += "\\";
	str.append(MAX_SHAPE_WIDTH, '_');
	str += "/";
	return (str);
}
