#include "gmock/gmock.h"
#include <string>

#include "Helper.h"

using namespace testing;

class HelperTest : public Test {
    public:
	    Helper<std::string> helper;
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
