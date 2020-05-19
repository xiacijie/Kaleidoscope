#include "lexer.hpp"


static std::string IdentifierStr;
static double NumVal;

//return the next token from stdin
static int gettok(){
    static int LastChar = ' ';

    //skip any whitespace
    while (isspace(LastChar))
        LastChar = getchar();

    if (isalpha(LastChar)) {
        IdentifierStr = LastChar;
        while (isalnum((LastChar=getchar())))
            IdentifierStr += LastChar;
        
        if (IdentifierStr == "def")
            return tok_def;
        
        if (IdentifierStr == "extern")
            return tok_extern;

        return tok_indentifier;
    }

    if (isdigit(LastChar) || LastChar == '.') {
        std::string NumStr;

        do {
            NumStr += LastChar;
            LastChar = getchar();

        } while (isdigit(LastChar) || LastChar == '.');

        NumVal = strtod(NumStr.c_str(), 0);
        return tok_number;
    }

    if (LastChar == '#') {
        //comment
        do
        {
            LastChar = getchar();
        } while (
            LastChar != EOF && LastChar != '\n' && LastChar != '\r'
        );


        if (LastChar != EOF) {
            return gettok();
        }
        
    }

    //Ckeck for end of file
    if (LastChar == EOF)
        return tok_eof;

    //Otherwise, just return the character as its ascii value
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}