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
    const TokenType _MINUS = "-";
    const TokenType _INVERSE = "!";
    const TokenType _ASTERISK = "*";
    const TokenType _SLASH = "/";
    const TokenType _EQ = "==";
    const TokenType _NOT_EQ = "!=";

    const TokenType _LT = "<"; // lower than
    const TokenType _GT = ">"; // greater than

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
    const TokenType _TRUE = "TRUE";
    const TokenType _FALSE = "FALSE";
    const TokenType _IF = "IF";
    const TokenType _ELSE = "ELSE";
    const TokenType _RETURN = "RETURN";

    // built-in 키워드 저장
    std::unordered_map<std::string, TokenType> keywords
    {
        {"fn", _FUNCTION},
        {"let", _LET},
        {"true", _TRUE},
        {"false", _FALSE},
        {"if", _IF},
        {"else", _ELSE},
        {"return", _RETURN}
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






