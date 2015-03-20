// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AShootPatternDefault.class.hpp                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 11:13:22 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/20 07:26:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASHOOTPATTERNDEFAULT_CLASS_HPP
# define ASHOOTPATTERNDEFAULT_CLASS_HPP

# include <ft_retro.hpp>
# include <IShootIA.class.hpp>
//# include <iostream>
//# include <stdexcept>

class AShootPatternDefault : public IShootIA
{
public:
	AShootPatternDefault();
	virtual ~AShootPatternDefault();

	int							tryShoot(Game const &g);

protected:
private:
	AShootPatternDefault(AShootPatternDefault const &src);
	AShootPatternDefault		&operator=(AShootPatternDefault const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, AShootPatternDefault const &rhs);

#endif // ************************************ ASHOOTPATTERNDEFAULT_CLASS_HPP //
