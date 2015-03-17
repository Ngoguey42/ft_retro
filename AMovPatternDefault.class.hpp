// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMovPatternDefault.class.hpp                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 10:44:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 10:50:35 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMOVPATTERNDEFAULT_CLASS_HPP
# define AMOVPATTERNDEFAULT_CLASS_HPP

# include <IMovIA.class.hpp>
//# include <string>
//# include <iostream>
//# include <stdexcept>

class AMovPatternDefault : public IMovIA
{
public:
	AMovPatternDefault();
	virtual ~AMovPatternDefault();

	int							tryMove(Game const &g);
protected:
private:
	AMovPatternDefault(AMovPatternDefault const &src);
	AMovPatternDefault			&operator=(AMovPatternDefault const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, AMovPatternDefault const &rhs);

#endif // ************************************** AMOVPATTERNDEFAULT_CLASS_HPP //
