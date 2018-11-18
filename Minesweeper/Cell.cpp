#include "stdafx.h"
#include "Cell.h"


Cell::Cell(bool bomb)
{
	this->bomb = bomb;
	this->triggered = false;
}

Cell::~Cell() {}


bool Cell::isTriggered()
{
	return triggered;
}


bool Cell::isBomb()
{
	return bomb;
}

bool Cell::trigger()
{
	this->triggered = true;
	if (this->bomb)
		return true;
	return false;
}

void Cell::setBomb()
{
	this->bomb = true;
}
