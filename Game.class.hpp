// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:09:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 12:28:56 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>

class Game
{
public:
	Game(int maxX, int maxY);
	virtual ~Game();
	int							getMaxX(void) const;
	int							getMaxY(void) const;

protected:
private:
	Game();
	Game(Game const &src);
	Game						&operator=(Game const &rhs);
	int const					_maxX;
	int const					_maxY;
};
//std::ostream					&operator<<(std::ostream &o, Game const &rhs);

#endif // **************************************************** GAME_CLASS_HPP //
