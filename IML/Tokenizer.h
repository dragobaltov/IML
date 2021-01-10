#pragma once
#include <string>
#include <vector>

class Tokenizer
{
private:
	bool leftArrowsMatchRightArrows(const std::string&) const;
	bool contains(const std::vector<char>&, char) const;
	std::vector<std::string> split(const std::string&, const std::vector<char>&) const;
	std::vector<std::string> removeEmptyTokens(const std::vector<std::string>&) const;
public:
	std::vector<std::string> tokenize(const std::string&) const;
};
