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
    
    "let result = add(five, ten);"
    "!-/*5;"
    "5 < 10 > 5;"
    
    "if (5 < 10) {"
    "   return true;"
    "} else {"
    "   return false;"
    "}"

    "10 == 10;"
    "10 != 9;"
    ;

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
        Token{token::_INVERSE, "!"},
        Token{token::_MINUS, "-"},
        Token{token::_SLASH, "/"},
        Token{token::_ASTERISK, "*"},
        Token{token::_INT, "5"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_INT, "5"},
        Token{token::_LT, "<"},
        Token{token::_INT, "10"},
        Token{token::_GT, ">"},
        Token{token::_INT, "5"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_IF, "if"},
        Token{token::_LPAREN, "("},
        Token{token::_INT, "5"},
        Token{token::_LT, "<"},
        Token{token::_INT, "10"},
        Token{token::_RPAREN, ")"},
        Token{token::_LBRACE, "{"},
        Token{token::_RETURN, "return"},
        Token{token::_TRUE, "true"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_RBRACE, "}"},
        Token{token::_ELSE, "else"},
        Token{token::_LBRACE, "{"},
        Token{token::_RETURN, "return"},
        Token{token::_FALSE, "false"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_RBRACE, "}"},
        Token{token::_INT, "10"},
        Token{token::_EQ, "=="},
        Token{token::_INT, "10"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_INT, "10"},
        Token{token::_NOT_EQ, "!="},
        Token{token::_INT, "9"},
        Token{token::_SEMICOLON, ";"},
        Token{token::_EOF, ""},
    };

    Lexer lexer = Lexer::New(input);

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