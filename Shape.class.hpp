// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Shape.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:57:42 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 08:55:58 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHAPE_CLASS_HPP
# define SHAPE_CLASS_HPP

# include <ft_retro.hpp>
// # include <AObject.class.hpp>
// # include <string>
# include <iostream>
//# include <stdexcept>

class Shape
{
public:
	virtual ~Shape();

	void						putShape(Game const &g, int x, int y) const;
	bool						shapeFits(Game const &g, int x, int y) const;
	
	Shape(char const fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
		  char const fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
		  char const bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH]);
	Shape(Shape const &src);
	std::string					shapeToString(void) const;
protected:	
	int							getLeftSize(void) const;
	int							getRightSize(void) const;
	int							getTopSize(void) const;
	int							getBottomSize(void) const;
	char const					**getFgChars(void) const;
	char const					**getFgColors(void) const;
	char const					**getBgColors(void) const;

private:
	Shape();
	Shape						&operator=(Shape const &rhs);
	char						_fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	char						_fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	char						_bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	int							_leftSize;
	int							_rightSize;
	int							_topSize;
	int							_bottomSize;
};
std::ostream					&operator<<(std::ostream &o, Shape const &rhs);

#endif // *************************************************** SHAPE_CLASS_HPP //
