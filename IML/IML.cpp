#include <iostream>
#include "Parser.h"

int main()
{
	std::vector<std::string> v = {"SRT-ORD", "\"ASC\"", "81", "3", "MAP-INC", "\"1\"", "4", "12", "55",
								  "AGG-AVG", "4", "8", "/AGG-AVG", "/MAP-INC", "22", "/SRT-ORD"};

	std::vector<std::string> v1 = {"SRT-DST", "SRT-SLC", "\"3\"", "57", "18", "9",
								   "MAP-INC", "\"-3\"", "4", "2", "2", "/MAP-INC",
								   "5", "/SRT-SLC", "/SRT-DST"};

	Parser p = Parser();
	std::vector<double> result = p.parse(v1);
	//slice tag reordering nums
	return 0;
}
