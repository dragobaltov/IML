#pragma once
#include "Tag.h"
#include <functional>

class MapTag : public Tag
{
private:
	double m_number;

	std::vector<double> map(const std::vector<double>& data)
	{
		std::vector<double> result;

		for (auto it = data.begin(); it != data.end(); ++it)
		{
			result.push_back(mappingFunc(*it, m_number));
		}

		return result;
	}
protected:
	virtual double mappingFunc(double x, double y) = 0;
public:
	MapTag(double number)
	{
		m_number = number;
	}

	// Inherited via Tag
	virtual std::vector<double> evaluate(const std::vector<double>& data) override
	{
		return map(data);
	}
};
