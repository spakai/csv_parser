#include "gmock/gmock.h" 
#include "CSVParser.h"

using namespace testing;
using namespace std;

class ACSVParser: public Test {
    public:
        CSVParser csv_parser;

    void SetUp() override {
        csv_parser.load("../csv/sample.csv");
    }
};

TEST_F(ACSVParser, GetNumberOfRecords) {
    
    ASSERT_THAT(csv_parser.rows(), Eq(5));

}

TEST_F(ACSVParser, GetNumberOfColumns) {
    ASSERT_THAT(csv_parser.cols(), Eq(5));
}

TEST_F(ACSVParser,ReadTheFirstLine) {
    std::string currentLine = csv_parser.readLine(1);
    
    ASSERT_THAT(currentLine, StrEq("A,B,C,D,E"));
}

TEST_F(ACSVParser,ReadTheFirstAndThenSecondLine) {
    std::string result;
    result = csv_parser.readLine(1);
    result = csv_parser.readLine(2);
    
    ASSERT_THAT(result, StrEq("1,2,3,4,5"));
}

TEST_F(ACSVParser,ReadTheLastLine) {
    std::string currentLine = csv_parser.readLine(5);
    
    ASSERT_THAT(currentLine, StrEq("12,DF,ER,AD,JK"));
}

TEST_F(ACSVParser, ReadAnInvalidLine) {
    ASSERT_THROW(csv_parser.readLine(100), std::out_of_range);
}

TEST_F(ACSVParser, GetValueOfLastColumn) {
    int row{3};
    int col{4};

    std::string value = csv_parser.getValue(row, col);
    ASSERT_THAT(value, Eq("P"));
}

TEST_F(ACSVParser, GetValueOfFirstColumn) {
    int row{5};
    int col{1};

    std::string value = csv_parser.getValue(row, col);
    ASSERT_THAT(value, Eq("DF"));
}

TEST_F(ACSVParser, GetValueOfInvalidColumn) {
    int row{3};
    int col{20};

    ASSERT_THROW(csv_parser.getValue(row, col), std::out_of_range);
}
