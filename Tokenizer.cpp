#include "Tokenizer.h"

Tokenizer::Tokenizer(string& row) {
    regex re("[,]+");
    sregex_token_iterator it(row.begin(), row.end(), re, -1);
    copy(it,sregex_token_iterator(), back_inserter(tokens)); 
}

string& Tokenizer::operator[](unsigned int i) {

    if ( i > tokens.size() ) { 
        throw std::out_of_range("index out of range");
    }

    return tokens.at(i);
}
