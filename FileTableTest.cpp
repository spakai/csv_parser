#include "gmock/gmock.h"
#include <string>

#include "FileTable.h"

using namespace testing;

class FileTableTest : public Test {
    public:
	    FileTable ft;

	    void SetUp() override {
		    ft.init("../csv/sample.csv", 5);
	    }
};

TEST_F(FileTableTest,OffsetsAndLengths) {
    ASSERT_THAT(ft.getNumberOfRows(),Eq(5));
}

TEST_F(FileTableTest, Iterator_ReadTillLastRowUsingForRange) {
    std::vector<std::string> tokens;
    for(auto currentRow : ft) {
        tokens = currentRow;
    }

    ASSERT_THAT(tokens[0],Eq("12"));
}

TEST_F(FileTableTest, Iterator_ReadTillLastRowUsingForBeginEnd) {
    std::vector<std::string> tokens;
    for(auto currentRow=ft.begin(); currentRow != ft.end() ; currentRow++) {
        tokens = *currentRow;
      }
    ASSERT_THAT(tokens[0], Eq("12"));
}
