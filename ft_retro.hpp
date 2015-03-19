// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_retro.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:57:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 12:36:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

class Game;
class Background;
class Scheduler;

class AObject;
class Shape;

class IMovIA;
class AMovPatternDefault;
class AMovPatternSheep;
class AMovPatternLombric;

class IShootIA;
class AShootPatternDefault;

class Snake;
class Pig;
class Sheep;

# include <objects_shapes.hpp>

# define DELTA_REFRESH_SCREEN 40000
# define DELTA_REFRESH_EVENTS DELTA_REFRESH_SCREEN

#endif // ****************************************************** FT_RETRO_HPP //
