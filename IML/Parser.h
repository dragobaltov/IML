#pragma once
#include <stack>
#include "Tag.h"

class Parser
{
private:
	std::stack<Tag*> tagsStack;
	std::stack<std::vector<double>> numsStack;

	void deleteTag();
public:
	/*!Receives the tags, their arguments and the numbers as strings. Converts them and calculates the result.*/
	std::vector<std::vector<double>> parse(const std::vector<std::string>&);
};