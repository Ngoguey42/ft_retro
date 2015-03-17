// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pig.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:58:27 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 10:53:42 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PIG_CLASS_HPP
# define PIG_CLASS_HPP

//# include <string>
# include <iostream>
# include <AObject.class.hpp>
# include <AMovPatternDefault.class.hpp>
//# include <stdexcept>

class Pig : public AObject, public AMovPatternDefault
{
public:
	Pig();
	virtual ~Pig();

	std::string const			&getName() const;
	Shape const					&getShape() const;
	bool						getDoesMove() const;
	bool						getDoesShoot() const;

	int							getPosX(void) const;
	int							getPosY(void) const;
	void						setPosX(int x);
	void						setPosY(int y);
	void						setPosXY(int x, int y);
	// Pig();

protected:
private:
	Pig(Pig const &src);
	Pig							&operator=(Pig const &rhs);

	static std::string const	_mobName;
	static Shape const			_mobShape;
	static bool const			_doesMove;
	static bool const			_doesShoot;
	
};
//std::ostream					&operator<<(std::ostream &o, Pig const &rhs);

#endif // ***************************************************** PIG_CLASS_HPP //
