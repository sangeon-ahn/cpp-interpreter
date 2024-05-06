#ifndef TOKEN
#define TOKEN

#include <string>
#include <unordered_map>
typedef std::string TokenType;

class Token {
    public:
        Token() = default;
        Token(TokenType type, std::string literal) : Type{type}, Literal{literal} {}
        TokenType Type;
        std::string Literal;
};

namespace token {
    const TokenType _ILLEGAL = "ILLEGAL";
    const TokenType _EOF = "EOF";

    // Identifiers + Literals
    const TokenType _IDENT = "IDENT";
    const TokenType _INT = "INT";

    // Operators
    const TokenType _ASSIGN = "=";
    const TokenType _PLUS = "+";

    // Delimiters
    const TokenType _COMMA = ",";
    const TokenType _SEMICOLON = ";";

    const TokenType _LPAREN = "("; 
    const TokenType _RPAREN = ")";
    const TokenType _LBRACE = "{";
    const TokenType _RBRACE = "}";

    // Keywords
    const TokenType _FUNCTION = "FUNCTION";
    const TokenType _LET = "LET";

    // built-in 키워드 저장
    std::unordered_map<std::string, TokenType> keywords
    {
        {"fn", _FUNCTION},
        {"let", _LET}
    };

    TokenType LookupIdent(std::string ident)
    {
        // built-in 키워드인 경우,
        if (keywords.find(ident) != keywords.end()) {
            return keywords[ident];
        }

        // user-defined 키워드인 경우,
        return _IDENT;
    }
}
#endif






