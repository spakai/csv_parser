#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Tokenizer {
    public:
        Tokenizer() {};
        virtual ~Tokenizer() {};
        virtual void tokenize(const std::string& csvrow) = 0;
        string& operator[] (unsigned int i);
        unsigned int size() const;

    protected:
        vector<std::string> tokens;
};
