#pragma once
#include "Tokenizer.h"
#include "Parser.h"

class Engine
{
private:
	Tokenizer m_tokenizer;
	Parser m_parser;

	void printResult(const std::vector<double>&) const;
public:
	Engine(const Tokenizer&, const Parser&);

	void run();
};
