#include <iostream>
#include "Engine.h"
#include "Tokenizer.h"
#include "Parser.h"

int main()
{
	Tokenizer tokenizer = Tokenizer();
	Parser parser = Parser();
	Engine engine = Engine(tokenizer, parser);

	engine.run();

	return 0;
}
