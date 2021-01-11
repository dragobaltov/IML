#include "TagsFactory.h"

#include "AggAvgTag.h"
#include "AggFstTag.h"
#include "AggLstTag.h"
#include "AggProTag.h"
#include "AggSumTag.h"
#include "MapIncTag.h"
#include "MapMltTag.h"
#include "SrtDstTag.h"
#include "SrtOrdTag.h"
#include "SrtRevTag.h"
#include "SrtSlcTag.h"

#include "Validator.h"
#include "StringTags.h"
#include "StringErrors.h"

Tag* TagsFactory::createTagWithNoParam(const std::string& tagStr)
{
	Tag* tag = nullptr;

	if (tagStr == StringTags::AGG_AVG)
	{
		tag = new AggAvgTag();
	}
	else if (tagStr == StringTags::AGG_FST)
	{
		tag = new AggFstTag();
	}
	else if (tagStr == StringTags::AGG_LST)
	{
		tag = new AggLstTag();
	}
	else if (tagStr == StringTags::AGG_PRO)
	{
		tag = new AggProTag();
	}
	else if (tagStr == StringTags::AGG_SUM)
	{
		tag = new AggSumTag();
	}
	else if (tagStr == StringTags::SRT_DST)
	{
		tag = new SrtDstTag();
	}
	else if (tagStr == StringTags::SRT_REV)
	{
		tag = new SrtRevTag();
	}

	return tag;
}

Tag* TagsFactory::createTagWithParam(const std::string& tagStr, const std::string& param)
{
	Tag* tag = nullptr;

	if (tagStr == StringTags::MAP_INC)
	{
		if (!Validator::isRealNumberArgument(param))
		{
			throw std::exception(StringErrors::INVALID_ARGUMENT.c_str());
		}

		double number = std::stod(param.substr(1, param.size() - 2));
		tag = new MapIncTag(number);
	}
	else if (tagStr == StringTags::MAP_MLT)
	{
		if (!Validator::isRealNumberArgument(param))
		{
			throw std::exception(StringErrors::INVALID_ARGUMENT.c_str());
		}

		double number = std::stod(param.substr(1, param.size() - 2));
		tag = new MapMltTag(number);
	}
	else if (tagStr == StringTags::SRT_ORD)
	{
		if (!Validator::isSortingOrderArgument(param))
		{
			throw std::exception(StringErrors::INVALID_ARGUMENT.c_str());
		}

		std::string order = param.substr(1, param.size() - 2);
		tag = new SrtOrdTag(order);
	}
	else if (tagStr == StringTags::SRT_SLC)
	{
		if (!Validator::isIntegerArgument(param))
		{
			throw std::exception(StringErrors::INVALID_ARGUMENT.c_str());
		}

		int index = std::stoi(param.substr(1, param.size() - 2));
		tag = new SrtSlcTag(index);
	}

	return tag;
}