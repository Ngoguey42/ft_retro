// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_retro.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/17 06:57:17 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/17 08:20:27 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

//# include <string>
//# include <iostream>
//# include <stdexcept>
# include <Game.class.hpp>

# define MAX_SHAPE_HEIGHT 3
# define MAX_SHAPE_WIDTH 3

# define TEST_TAB (const char[MAX_SHAPE_HEIGHT][MAX_SHAPE_WIDTH]){\
{'\0', '\0', '\0'},\
{'\0', '%', '\0'},\
{'\0', '\0', '\0'}\
}

# define TEST_TAB2 {\
{'\0', '?', '\0'},\
{'\0', 'O', '\0'},\
{'\0', '\0', '\0'}\
}

#endif // ****************************************************** FT_RETRO_HPP //
