#include "Tokenizer.h"
#include <algorithm>
#include <iterator>

bool Tokenizer::leftArrowsMatchRightArrows(const std::string& input) const
{
	bool openTag = false;

	for (char c : input)
	{
		if (c == '<')
		{
			if (openTag)
			{
				return false;
			}

			openTag = true;
		}
		else if (c == '>')
		{
			if (!openTag)
			{
				return false;
			}

			openTag = false;
		}
	}

	return !openTag;
}

bool Tokenizer::contains(const std::vector<char>& elements, char elem) const
{
	for (char element : elements)
	{
		if (elem == element)
		{
			return true;
		}
	}

	return false;
}

std::vector<std::string> Tokenizer::split(const std::string& input, const std::vector<char>& delimiters) const
{
	std::vector<std::string> tokens;
	std::string curr = "";
	size_t i = 0;

	while (i < input.size())
	{
		if (contains(delimiters, input[i]))
		{
			tokens.push_back(curr);
			curr = "";
		}
		else
		{
			curr += input[i];
		}

		++i;
	}

	return tokens;
}

std::vector<std::string> Tokenizer::removeEmptyTokens(const std::vector<std::string>& tokens) const
{
	std::vector<std::string> result;

	std::copy_if(tokens.begin(), tokens.end(), std::back_inserter(result), 
		[](const std::string& token) {return token != ""; });

	return result;
}

std::vector<std::string> Tokenizer::tokenize(const std::string& input) const
{
	if (!leftArrowsMatchRightArrows(input))
	{
		throw std::exception("Opening tag arrows does not match closing tag arrows!");
	}

	std::vector<char> delimiters = { '<', '>', ' ' };
	std::vector<std::string> tokens = split(input, delimiters);
	std::vector<std::string> nonEmptyTokens = removeEmptyTokens(tokens);
	
	return nonEmptyTokens;
}