// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_retro.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:57:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 07:32:52 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

class Game;
class Background;

class AObject;
class Shape;

class IMovIA;
class AMovPatternDefault;

class IShootIA;
class AShootPatternDefault;

class Pig;

//# include <string>
//# include <iostream>
//# include <stdexcept>

# define MAX_SHAPE_HEIGHT 3
# define MAX_SHAPE_WIDTH MAX_SHAPE_HEIGHT

# define MID_SHAPE_INDEX 1

# define SHAPE_HEIGHT_DELTA (-((MAX_SHAPE_HEIGHT) / 2))
# define SHAPE_WIDTH_DELTA (-((MAX_SHAPE_WIDTH) / 2))

# define DELTA_REFRESH_SCREEN 40000
# define DELTA_REFRESH_EVENTS 100000

# define TEST_TAB (const char[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH]){	\
{'\0', '?', '\0'},\
{'\0', 'O', '\0'},\
{'\0', '\0', '\0'}\
}

# define TEST_TAB2 {\
{'\0', '?', '\0'},\
{'\0', 'O', '\0'},\
{'\0', '\0', '\0'}\
}


#endif // ****************************************************** FT_RETRO_HPP //
