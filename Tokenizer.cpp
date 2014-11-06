#include "Tokenizer.h"

Tokenizer::Tokenizer(const string& csv) {
#if GCC_VERSION > 40803
    regex re("[,]+");
    sregex_token_iterator it(csv.begin(), csv.end(), re, -1);
    copy(it,sregex_token_iterator(), back_inserter(tokens)); 
#else
    istringstream ss(csv);
    while (!ss.eof()) {
        std::string str;
        getline(ss, str,',');
        tokens.push_back(str); 
    }
#endif
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
