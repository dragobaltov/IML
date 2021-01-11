#pragma once
#include "AggTag.h"

/*!Returns the last value given*/
class AggLstTag : public AggTag
{
protected:
	virtual double aggregate(const std::vector<double>& data) override
	{
		return data.back();
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::AGG_LST;
	}
};
