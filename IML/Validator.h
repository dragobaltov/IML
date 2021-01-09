#pragma once
#include <string>

/*const std::string& AGG_AVG = "AGG-AVG";
const std::string& AGG_FST = "AGG-FST";
const std::string& AGG_LST = "AGG-LST";
const std::string& AGG_SUM = "AGG-SUM";
const std::string& AGG_PRO = "AGG-PRO";

const std::string& MAP_INC = "MAP-INC";
const std::string& MAP_MLT = "MAP-MLT";

const std::string& SRT_ORD = "SRT-ORD";
const std::string& SRT_DST = "SRT-DST";
const std::string& SRT_REV = "SRT-REV";
const std::string& SRT_SLC = "SRT-SLC";

const std::string& ASC_ORDER = "ASC";
const std::string& DSC_ORDER = "DSC";*/

static class Validator
{
private:
	static bool isArgument(const std::string&);
	static bool isInteger(const std::string&);
public:
	static bool isOpeningTagWithParam(const std::string&);
	static bool isOpeningTagWithNoParam(const std::string&);
	static bool isClosingTag(const std::string&);
	static bool isRealNumber(const std::string&);
	static bool isRealNumberArgument(const std::string&);
	static bool isIntegerArgument(const std::string&);
	static bool isSortingOrderArgument(const std::string&);
};
