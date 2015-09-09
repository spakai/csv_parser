#include "gmock/gmock.h"
#include <string>

#include "Helper.h"

using namespace testing;

class HelperTest : public Test {
    public:
	    Helper helper;
};

TEST_F(HelperTest,DuplicateLine) {
    std::string s("XYZ");
    helper.checkDuplicate(s);
    ASSERT_THROW(helper.checkDuplicate(s), DuplicateException);
}

TEST_F(HelperTest,NoDuplicateLine) {
    std::string s("XYZ");
    helper.checkDuplicate(s);
}

TEST_F(HelperTest,EmptyLine) {
    std::string s("");
    ASSERT_THROW(helper.checkEmpty(s), EmptyLineException);
}
TEST_F(HelperTest,InvalidNumberOfColumns) {
    std::string s("1,2,3");
    ASSERT_THROW(helper.checkIfInvalidNumberOfColumns(s,',',2), InvalidNumberOfColumns);
}
