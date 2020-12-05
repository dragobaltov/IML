#pragma once
#include "MapTag.h"

/*! Multiplies each element of the list with the given parameter*/
class MapMltTag : public MapTag
{
protected:
	virtual double mappingFunc(double x, double y) override
	{
		return x * y;
	}
};
