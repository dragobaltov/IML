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
public:
	MapIncTag(double number) : MapTag(number) {}

	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::MAP_INC;
	}
};
