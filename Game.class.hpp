// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:09:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 07:10:01 by ngoguey          ###   ########.fr       //
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
	Game();
	virtual ~Game();


protected:
private:
	Game(Game const &src);
	Game						&operator=(Game const &rhs);
	
};
//std::ostream					&operator<<(std::ostream &o, Game const &rhs);

#endif // **************************************************** GAME_CLASS_HPP //
