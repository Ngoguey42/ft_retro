// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scheduler.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/19 10:41:42 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/19 12:23:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Scheduler.class.hpp"
#include <cstdlib>

// ************************************************************************** //
// **************************************************** STATICS *** STATICS * //
// * STATICS *** STATICS **************************************************** //
// ************************************************************************** //
// ****************************************** CONSTRUCTORS *** CONSTRUCTORS * //
Scheduler::Scheduler(clock_t waitTime, clock_t waveCD) :
	_lastWave(std::clock() + waitTime), _waveCD(waveCD), _waveCount(0)
{
	// std::cout << "[Scheduler]() Ctor called" << std::endl;
	return ;
}

// * CONSTRUCTORS *** CONSTRUCTORS ****************************************** //
// ************************************************************************** //
// ******************************************** DESTRUCTORS *** DESTRUCTORS * //
Scheduler::~Scheduler()
{
	// std::cout << "[Scheduler]() Dtor called" << std::endl;
	return ;
}

// * DESTRUCTORS *** DESTRUCTORS ******************************************** //
// ************************************************************************** //
// ************************************************ OPERATORS *** OPERATORS * //
// * OPERATORS *** OPERATORS ************************************************ //
// ************************************************************************** //
// **************************************************** GETTERS *** GETTERS * //
// * GETTERS *** GETTERS **************************************************** //
// ************************************************************************** //
// **************************************************** SETTERS *** SETTERS * //
// * SETTERS *** SETTERS **************************************************** //
// ************************************************************************** //
void						Scheduler::tryNewWave(Game &g)
{
	while (std::clock() >= this->_lastWave + this->_waveCD)
	{

		// std::cout << "new wave" << std::endl;
		
		
		int			pool;
		int			pool2;

		this->_lastWave += this->_waveCD;
		this->_waveCount++;
		if (0)
		{
			;
		}
		else
		{
			pool = std::rand() % (this->_waveCount * 2 - 1) + 1;
			pool2 = std::rand() % pool;
			g.popSheep(pool2);
			g.popPig(pool - pool2);
		}
	}
	return ;
}