// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AObject.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:11:33 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 12:05:33 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AOBJECT_CLASS_HPP
# define AOBJECT_CLASS_HPP

# include <ft_retro.hpp>
# include <Shape.class.hpp>
# include <Game.class.hpp>

# include <iostream>
//# include <stdexcept>

class AObject
{
public:
	AObject();
	virtual ~AObject();

	virtual std::string const	&getName() const = 0;
	virtual	Shape const			&getShape() const = 0;
	virtual	bool				getDoesMove() const = 0;
	virtual bool				getDoesShoot() const = 0;

	virtual void				moveCall(Game const &g) = 0;

	virtual int					getPosX(void) const;
	virtual int					getPosY(void) const;
	bool						getDeleteObject(void) const;

	virtual void				setPosX(int x);
	virtual void				setPosY(int y);
	
protected:
	int							_posX;
	int							_posY;
	bool						_deleteObject;

private:
	AObject(AObject const &src);
	AObject						&operator=(AObject const &rhs);
	
};
std::ostream					&operator<<(std::ostream &o, AObject const &rhs);

#endif // ************************************************* AOBJECT_CLASS_HPP //
