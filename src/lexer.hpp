#include <string>

extern std::string IdentifierStr;
extern double NumVal;

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum Token {
    tok_eof = -1,

    //commands
    tok_def = -2,
    tok_extern = -3,

    // primary
    tok_indentifier = -4,
    tok_number = -5,
};


static int gettok();
