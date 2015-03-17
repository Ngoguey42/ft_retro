// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 07:09:45 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 17:44:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <string>
# include <vector>
class AObject;
# include <AObject.class.hpp>
//# include <stdexcept>

class Game
{
public:
	Game(int maxX, int maxY);
	virtual ~Game();
	int							getMaxX(void) const;
	int							getMaxY(void) const;

	std::string					*getDstFgChars(void) const;
	char						*getDstFgColors(void) const;
	char						*getDstBgColors(void) const;
	void						putImage(void) const;
	void						putObjects(void) const;

	void						setFgChar(int x, int y, char c) const;
	
	std::vector<AObject*>		_objsVector;
protected:
private:
	Game();
	Game(Game const &src);
	Game						&operator=(Game const &rhs);
	int const					_maxX;
	int const					_maxY;
	std::string					*_dstFgChars;
	char						*_dstFgColors;
	char						*_dstBgColors;
};
//std::ostream					&operator<<(std::ostream &o, Game const &rhs);

#endif // **************************************************** GAME_CLASS_HPP //
