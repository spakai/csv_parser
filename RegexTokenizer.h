#pragma once
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#include "Tokenizer.h"

#if GCC_VERSION > 40803 // Test for GCC > 4.8.3
#include <regex>
#endif

using namespace std;

class RegexTokenizer : public Tokenizer {

    public:
        RegexTokenizer() {};
        ~RegexTokenizer() {};
        virtual void tokenize(const std::string& csvrow);
};
