// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pig.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:58:27 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 08:08:11 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PIG_CLASS_HPP
# define PIG_CLASS_HPP

//# include <string>
# include <iostream>
# include <AObject.class.hpp>
//# include <stdexcept>

class Pig : public AObject
{
public:
	Pig();
	virtual ~Pig();

	virtual std::string const   &getName() const;
	virtual bool				getDoesMove() const;
	virtual bool				getDoesShoot() const;
	// Pig();

protected:
private:
	Pig(Pig const &src);
	Pig							&operator=(Pig const &rhs);

	static std::string const	_mobName;
	static char const			_fgChars[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	static char const			_fgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	static char const			_bgColors[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH];
	static bool const			_doesMove;
	static bool const			_doesShoot;
	
};
//std::ostream					&operator<<(std::ostream &o, Pig const &rhs);

#endif // ***************************************************** PIG_CLASS_HPP //
