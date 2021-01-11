#pragma once
#include "Tokenizer.h"
#include "Parser.h"

/*!Receives the input and prints the result.*/
class Engine
{
private:
	const std::string INPUT_FILE_PROMPT = "Input file name: ";
	const std::string OUTPUT_FILE_PROMPT = "Output file name: ";

	Tokenizer m_tokenizer;
	Parser m_parser;

	std::string getUserInput(const std::string&) const;
	std::string readFile(const std::string&) const;
	void saveResults(const std::string&, const std::vector<std::vector<double>>&) const;
public:
	Engine(const Tokenizer&, const Parser&);

	void run();
};
