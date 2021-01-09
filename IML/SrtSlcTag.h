#pragma once
#include "SrtTag.h"

/*! Slices the list from the given index to the end*/
class SrtSlcTag : public SrtTag
{
private:
	int m_index;
protected:
	virtual std::vector<double> sort(const std::vector<double>& data) override
	{
		if (m_index >= data.size())
		{
			return std::vector<double>();
		}

		std::vector<double> result;
		auto it = data.begin();

		for (int i = 0; i < m_index; ++i)
			++it;

		for (; it != data.end(); ++it)
			result.push_back(*it);

		return result;
	}
public:
	SrtSlcTag(int index)
	{
		m_index = index;
	}

	virtual bool closingTagIsValid(const std::string& tag) override
	{
		return tag == StringTags::SRT_SLC;
	}
};
