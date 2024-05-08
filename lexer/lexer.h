#include <string>
#include <string_view>
#include <iostream>
#include "../token/token.h"
using namespace std;

class Lexer
{
    public:
        Lexer() = default;
        Lexer(std::string_view input) : m_input{input.data()} {}
        void readChar();
        char peekChar();
        Token NextToken();
        static Lexer New(std::string_view input) {
            auto l = Lexer{input};
            l.readChar();
            return l;
        }

    private:
        std::string m_input; 
        int m_position {};
        int m_readPosition {};
        char m_ch {};

        Token newToken(TokenType tokenType, char ch);
        std::string readIdentifier();
        bool isLetter(char ch);
        void skipWhitespace();
        std::string readNumber();
};

void Lexer::readChar()
{
    if (m_readPosition >= m_input.length()) {
        m_ch = '\0'; // 마지막 도달시 null character로 교체. 
    } else {
        m_ch = m_input[m_readPosition];
    }
    m_position = m_readPosition;
    ++m_readPosition;
}

char Lexer::peekChar()
{
    if (m_readPosition >= m_input.length()) {
        return '\0';
    }
    return m_input[m_readPosition];
}

Token Lexer::NextToken()
{
    Token tok;

    skipWhitespace();

    switch (m_ch)
    {
    case '=':
        if (peekChar() == '=') {
            char ch = m_ch;
            readChar();
            tok = Token{token::_EQ, string(1, ch) + ch};
        } else {
            tok = newToken(token::_ASSIGN, m_ch);
        }
        break;
    case '+':
        tok = newToken(token::_PLUS, m_ch);
        break;
    case '-':
        tok = newToken(token::_MINUS, m_ch);
        break;
    case '!':
        if (peekChar() == '=') {
            char ch = m_ch;
            readChar();
            tok = Token{token::_NOT_EQ, string(1, ch) + m_ch};
        } else {
            tok = newToken(token::_INVERSE, m_ch);
        }
        break;
    case '/':
        tok = newToken(token::_SLASH, m_ch);
        break;
    case '*':
        tok = newToken(token::_ASTERISK, m_ch);
        break;
    case '<':
        tok = newToken(token::_LT, m_ch);    
        break;
    case '>':
        tok = newToken(token::_GT, m_ch);
        break;
    case ';':
        tok = newToken(token::_SEMICOLON, m_ch);
        break;
    case '(':
        tok = newToken(token::_LPAREN, m_ch);
        break;
    case ')':
        tok = newToken(token::_RPAREN, m_ch);
        break;
    case ',':
        tok = newToken(token::_COMMA, m_ch);
        break;
    case '{':
        tok = newToken(token::_LBRACE, m_ch);
        break;
    case '}':
        tok = newToken(token::_RBRACE, m_ch);
        break;
    case '\0':
        tok.Literal = "";
        tok.Type = token::_EOF;
        break;
    default:
        // 나머지 경우는 identifier, 숫자, invalid값 중 하나

        if (isLetter(m_ch)) {
            tok.Literal = readIdentifier();
            tok.Type = token::LookupIdent(tok.Literal);
            return tok; // readIdentifier()에서 이미 readChar() 해줬기 때문에 early-return
        } else if (isdigit(m_ch)) {
            tok.Type = token::_INT;
            tok.Literal = readNumber();
            return tok;
        } else {
            tok = newToken(token::_ILLEGAL, m_ch);
        }
        break;
    }

    readChar();
    return tok;
}

std::string Lexer::readNumber()
{
    int pos = m_position;
    while (isdigit(m_ch)) {
        readChar();
    }

    return m_input.substr(pos, m_position - pos);
}

void Lexer::skipWhitespace()
{
    while (m_ch == ' ' || m_ch == '\t' || m_ch == '\n' || m_ch == '\r') {
        readChar();
    }
}

std::string Lexer::readIdentifier()
{
    int pos = m_position;
    while (isLetter(m_ch)) {
        readChar();
    }
    return m_input.substr(pos, m_position - pos);
}

bool Lexer::isLetter(char ch)
{
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

Token Lexer::newToken(TokenType tokenType, char ch)
{
    return Token{tokenType, std::string(1, ch)};
}




