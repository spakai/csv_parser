#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

class Tokenizer {

    public:
        Tokenizer(const string& row);
        ~Tokenizer() {};
        string& operator[] (unsigned int i);
        unsigned int size() const;

    private:
        vector<std::string> tokens;
};
