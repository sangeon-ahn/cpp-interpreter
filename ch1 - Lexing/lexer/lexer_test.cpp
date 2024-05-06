#include "../token/token.h"
#include "lexer.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
 
void TestNextToken()
{
    string input = "let five = 5;"
    "let ten = 10;"
    "let add = fn(x, y) {"
    " x + y;"
    "};"
    "let result = add(five, ten);";

    vector<Token> tests {
        Token{token::_LET, "let"},
        Token{token::_IDENT, "five"},
        Token{token::_ASSIGN, "="},
        Token{token::_INT, "5"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_LET, "let"},
        Token{token::_IDENT, "ten"},
        Token{token::_ASSIGN, "="},
        Token{token::_INT, "10"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_LET, "let"},
        Token{token::_IDENT, "add"},
        Token{token::_ASSIGN, "="},
        Token{token::_FUNCTION, "fn"},
        Token{token::_LPAREN, "("},
        Token{token::_IDENT, "x"},
        Token(token::_COMMA, ","),
        Token{token::_IDENT, "y"},
        Token{token::_RPAREN, ")"},
        Token{token::_LBRACE, "{"},
        Token{token::_IDENT, "x"},
        Token{token::_PLUS, "+"},
        Token{token::_IDENT, "y"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_RBRACE, "}"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_LET, "let"},
        Token{token::_IDENT, "result"},
        Token{token::_ASSIGN, "="},
        Token{token::_IDENT, "add"},
        Token{token::_LPAREN, "("},
        Token{token::_IDENT, "five"},
        Token{token::_COMMA, ","},
        Token{token::_IDENT, "ten"},
        Token{token::_RPAREN, ")"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_EOF, ""},
    };

    Lexer lexer = New(input);

    int idx = 1;
    int failed_cnts = 0;
    int total_test_cnts = tests.size();

    Token tok;
    for (const auto& expectedToken : tests) {
        tok = lexer.NextToken();

        if (tok.Type != expectedToken.Type) {
            cout << idx << "th test failed. " << "expectedType=" << expectedToken.Type << " got Type=" << tok.Type << endl;
            ++failed_cnts;
        }

        if (tok.Literal != expectedToken.Literal) {
            cout << idx << "th test failed. " << "expectedLiteral=" << expectedToken.Literal << "got Literal=" << tok.Literal << endl;
            ++failed_cnts;
        }
        ++idx;
    }

    cout << "result: " << "total=" << 2 * total_test_cnts << " success=" << 2 * total_test_cnts - failed_cnts << " failed=" << failed_cnts << endl;
}

int main()
{
    TestNextToken();
}