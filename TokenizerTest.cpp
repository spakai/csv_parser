#include "gmock/gmock.h" 
#include "Tokenizer.h"

using namespace testing;

TEST(AToken,GetFirstColumnofARow) {
    std::string s{"A,B,C"};
    Tokenizer tok(s);
    ASSERT_THAT(tok[0],Eq("A"));
}

TEST(AToken, GetLastColumnofARow) {
    std::string s{"A,B,C"};
    Tokenizer tok(s);
    ASSERT_THAT(tok[2], Eq("C"));
}
