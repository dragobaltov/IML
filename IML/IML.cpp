#include <iostream>
#include "Engine.h"
#include "Tokenizer.h"
#include "Parser.h"

/*! \mainpage
* \section intro_sec External resources
* <a href="https://github.com/dragobaltov/IML">GitHub Repository</a>
*/

int main()
{
	Tokenizer tokenizer = Tokenizer();
	Parser parser = Parser();
	Engine engine = Engine(tokenizer, parser);

	engine.run();

	return 0;
}
