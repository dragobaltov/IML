#pragma once
#include "MapTag.h"

/*! Increments each value of the list with the given parameter*/
class MapIncTag : public MapTag
{
protected:
	// Inherited via MapTag
	virtual double mappingFunc(double x, double y) override
	{
		return x + y;
	}
};
