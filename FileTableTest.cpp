#include "gmock/gmock.h"
#include <string>

#include "FileTable.h"

using namespace testing;

class FileTableTest : public Test {
    public:
	    FileTable ft;

	    void SetUp() override {
		    ft.init("../csv/sample.csv");
	    }
};

class StreamTableTest : public Test {
    public:
	    FileTable ft;

	    void SetUp() override {
        std::istringstream ss {"A1,A2,A3,A4\n,B1,B2,B3,B4\nC1,C2,C3,C4\nD1,D2,D3,D4\nE1,E2,E3,E4\n"};
		    ft.init(&ss);
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


TEST_F(StreamTableTest,OffsetsAndLengths) {
    ASSERT_THAT(ft.getNumberOfRows(),Eq(5));
}
