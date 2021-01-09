#pragma once
#include "AggTag.h"

class AggFstTag : public AggTag
{
protected:
	virtual double aggregate(const std::vector<double>& data) override
	{
		return data.front();
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) override
	{
		return tag == StringTags::AGG_FST;
	}
};
