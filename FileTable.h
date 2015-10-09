#pragma once

#include "Table.h"
#include "Helper.h"
#include <sstream>

class FileTable : public Table{
    public:
        FileTable() {};
        ~FileTable() {};
        void init(const std::string& filename, int numberOfColumns);
        std::vector<std::string> tokenize(const std::string& csvrow, char delim);
        int getNumberOfRows() override;
        std::vector<std::string> getRow(int index) override;

    private:
        std::ifstream csv_file;
        std::vector<int> offsets;
        std::vector<int> lengths;

};
