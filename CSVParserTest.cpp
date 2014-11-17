#include "gmock/gmock.h" 
#include "CSVParser.h"
#include "GetLineTokenizer.h"

using namespace testing;
using namespace std;

class ACSVParser: public Test {
    public:
        GetLineTokenizer tokenizer; 
        //CSVParser csv_parser(tokenizer);

    virtual void SetUp() {
//        csv_parser.load("../csv/sample.csv");
    }
};

TEST_F(ACSVParser, GetNumberOfRecords) {
    CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");

    ASSERT_THAT(csv_parser.rows(), Eq(5));

}

TEST_F(ACSVParser, GetNumberOfColumns) {
   CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");


    ASSERT_THAT(csv_parser.cols(), Eq(5));
}

TEST_F(ACSVParser,ReadTheFirstLine) {
   CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");


    std::string currentLine = csv_parser.readLine(1);
    
    ASSERT_THAT(currentLine, StrEq("A,B,C,D,E"));
}

TEST_F(ACSVParser,ReadTheFirstAndThenSecondLine) {
   CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");


    std::string result;
    result = csv_parser.readLine(1);
    result = csv_parser.readLine(2);
    
    ASSERT_THAT(result, StrEq("1,2,3,4,5"));
}

TEST_F(ACSVParser,ReadTheLastLine) {
   CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");


    std::string currentLine = csv_parser.readLine(5);
    
    ASSERT_THAT(currentLine, StrEq("12,DF,ER,AD,JK"));
}

TEST_F(ACSVParser, ReadAnInvalidLine) {
   CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");


    ASSERT_THROW(csv_parser.readLine(100), std::out_of_range);
}

TEST_F(ACSVParser, GetValueOfLastColumn) {
    int row{3};
    int col{4};
    CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");

    std::string value = csv_parser.getValue(row, col);
    ASSERT_THAT(value, Eq("P"));
}

TEST_F(ACSVParser, GetValueOfFirstColumn) {
    int row{5};
    int col{1};
   CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");


    std::string value = csv_parser.getValue(row, col);
    ASSERT_THAT(value, Eq("DF"));
}

TEST_F(ACSVParser, GetValueOfInvalidColumn) {
    int row{3};
    int col{20};
   CSVParser csv_parser(tokenizer);
    csv_parser.load("../csv/sample.csv");


    ASSERT_THROW(csv_parser.getValue(row, col), std::out_of_range);
}
