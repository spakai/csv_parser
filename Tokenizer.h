#pragma once
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#include <string>
#include <vector>
#include <algorithm>
#if GCC_VERSION > 40803 // Test for GCC > 4.8.3
#include <regex>
#else
#include <sstream>
#endif

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
