#include <iostream>
#include <string>
#include "../lexer/lexer.h"
#include "../token/token.h"

namespace repl {
    const string PROMPT = ">> ";

    void Start(istream& in, ostream& out)
    {
        std::string line;
        Lexer lexer;

        while (in >> line) {
            lexer = Lexer::New(line);

            for (auto tok = lexer.NextToken(); tok.Type != token::_EOF; tok = lexer.NextToken()) {
                out << "{Type:" << tok.Type << " Literal:" << tok.Literal << std::endl;
            }
        }
    }
}




