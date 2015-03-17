// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_retro.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:57:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 18:16:29 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>

# define MAX_SHAPE_HEIGHT 3
# define MAX_SHAPE_WIDTH 3
# define SHAPE_HEIGHT_DELTA (-((MAX_SHAPE_HEIGHT) / 2))
# define SHAPE_WIDTH_DELTA (-((MAX_SHAPE_WIDTH) / 2))

# define DELTA_REFRESH 40000
# define DELTA_EVENTS 100000

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

# include <Game.class.hpp>

#endif // ****************************************************** FT_RETRO_HPP //
