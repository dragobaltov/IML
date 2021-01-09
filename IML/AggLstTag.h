#pragma once
#include "AggTag.h"

class AggLstTag : public AggTag
{
protected:
	virtual double aggregate(const std::vector<double>& data) override
	{
		return data.back();
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) override
	{
		return tag == StringTags::AGG_LST;
	}
};
