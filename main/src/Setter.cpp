// Setter.cpp
//
// Implemetation of Setter class
/// \author  Mike McCauley (mikem@open.com.au)
///
// Copyright (C) 2010 Mike McCauley
// $Id: Setter.cpp,v 1.2 2010/06/21 01:33:53 mikem Exp $

#include "Setter.h"

/////////////////////////////////////////////////////////////////////
Setter::Setter()
{
    _target = 0;
    _failsafeValue = 0;
}

/////////////////////////////////////////////////////////////////////
Setter::Setter(Setter* target)
{
    _target = target;
    _failsafeValue = 0;
}

/////////////////////////////////////////////////////////////////////
void Setter::input(int value)
{
    if (_target)
	_target->input(value);
}

/////////////////////////////////////////////////////////////////////
void Setter::failsafe()
{
    if (_target)
	_target->failsafe();
}

/////////////////////////////////////////////////////////////////////
void Setter::setTarget(Setter* target)
{
    _target = target;
}

/////////////////////////////////////////////////////////////////////
void Setter::setFailsafeValue(int failsafeValue)
{
    _failsafeValue = failsafeValue;
}

/////////////////////////////////////////////////////////////////////
int Setter::failsafeValue()
{
    return _failsafeValue;
}

