#pragma once
#include "AggTag.h"

class AggFstTag : public AggTag
{
protected:
	virtual double aggregate(const std::list<double>& data) override
	{
		return data.front();
	}
};
