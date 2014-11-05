#include "Tokenizer.h"

Tokenizer::Tokenizer(const string& csv) {
    regex re("[,]+");
    sregex_token_iterator it(csv.begin(), csv.end(), re, -1);
    copy(it,sregex_token_iterator(), back_inserter(tokens)); 
}

string& Tokenizer::operator[](unsigned int i) {

    if ( i > tokens.size() ) { 
        throw std::out_of_range("index out of range");
    }

    return tokens.at(i);
}

unsigned int Tokenizer::size() const {
    return tokens.size();
}
