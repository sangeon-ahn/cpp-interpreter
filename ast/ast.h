#include <string>
#include <vector>
class Node
{
    public:
        virtual std::string TokenLiteral() = 0;
};

class Statement
{
    public:
        void statementNode();
    private:
        Node node;
};

class Expression
{
    public:
        void expressionNode();
    public:
        void expressionNode();
};

class Program
{
    public:
        std::string TokenLiteral();
    private:
        std::vector<Statement> m_statements;
};
std::string Program::TokenLiteral()
{
    if (m_statements.size() > 0) {
        return m_statements[0].TokenLiteral();
    } else {
        return "";
    }
}


