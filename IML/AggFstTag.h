#pragma once
#include "AggTag.h"

/*!Returns the first value given*/
class AggFstTag : public AggTag
{
protected:
	virtual double aggregate(const std::vector<double>& data) override
	{
		return data.front();
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::AGG_FST;
	}
};
