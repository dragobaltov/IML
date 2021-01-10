#pragma once
#include "SrtTag.h"
#include <algorithm>

/*! 
* Sorts the list in ascending order(if the given parameter is ASC) or
* in descending order(if the given parameter is DSC).
*/
class SrtOrdTag : public SrtTag
{
private:
	std::string m_order;
protected:
	virtual std::vector<double> sort(const std::vector<double>& data) override
	{
		std::vector<double> result = data;

		if (m_order == "ASC")
		{
			std::sort(result.begin(), result.end());
		}
		else if(m_order == "DSC")
		{
			std::sort(result.begin(), result.end(), std::greater<double>());
		}

		return result;
	}
public:
	SrtOrdTag(const std::string& order)
	{
		m_order = order;
	}

	virtual bool closingTagIsValid(const std::string& tag) const override
	{
		return tag == '/' + StringTags::SRT_ORD;
	}
};
