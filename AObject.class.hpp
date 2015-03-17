// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:11:33 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 07:45:31 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AOBJECT_CLASS_HPP
# define AOBJECT_CLASS_HPP

# include <string>
# include <Shape.class.hpp>
//# include <iostream>
//# include <stdexcept>

class AObject : public Shape
{
public:
	AObject(char const fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
			char const fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH],
			char const bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH]);
	virtual ~AObject();

	virtual std::string const	&getName() const = 0;
	virtual	bool				getDoesMove() const = 0;
	virtual bool				getDoesShoot() const = 0;

	int							getPosX(void) const;
	int							getPosY(void) const;
	
protected:
	int							_posX;
	int							_posY;
private:
	AObject();
	AObject(AObject const &src);
	AObject						&operator=(AObject const &rhs);
	
};
//std::ostream					&operator<<(std::ostream &o, AObject const &rhs);

#endif // ************************************************* AOBJECT_CLASS_HPP //
