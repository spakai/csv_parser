#include "gmock/gmock.h"
#include "FileTable.h"

using namespace testing;

class FileTableExceptionTest : public Test {
    public:
	    FileTable ft;
};

TEST_F(FileTableExceptionTest, DuplicateLine) {
  ASSERT_THROW(ft.init("../csv/dup.csv",5), FileTableException);
}

TEST_F(FileTableExceptionTest, EmptyLine) {
  ASSERT_THROW(ft.init("../csv/empty.csv",5), FileTableException);
}

TEST_F(FileTableExceptionTest, InvalidNumberOfCols) {
  ASSERT_THROW(ft.init("../csv/empty.csv",5), FileTableException);
}
