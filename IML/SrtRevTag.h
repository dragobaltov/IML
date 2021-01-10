#pragma once
#include "SrtTag.h"

/*! Reverses the list*/
class SrtRevTag : public SrtTag
{
protected:
	virtual std::vector<double> sort(const std::vector<double>& data) override
	{
		std::vector<double> result;
		auto begin = data.begin();
		auto end = data.end();

		if (begin != end)
		{
			for (auto it = --end; it != begin; --it)
				result.push_back(*it);

			result.push_back(*begin);
		}

		return result;
	}
public:
	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::SRT_REV;
	}
};
