#pragma once
#include "AggTag.h"

class AggLstTag : public AggTag
{
protected:
	virtual double aggregate(const std::list<double>& data) override
	{
		return data.back();
	}
};
