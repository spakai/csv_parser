#include "Tokenizer.h"

string& Tokenizer::operator[](unsigned int i) {
    return tokens.at(i);
}

unsigned int Tokenizer::size() const {
    return tokens.size();
}
