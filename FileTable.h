#pragma once

#include "Table.h"
#include <sstream>
#include <istream>
#include <fstream>

class FileTable : public Table {
    public:
        FileTable() {};
        ~FileTable();
        void init(const std::string& filename);
        void init(std::istream *stream);
        std::vector<std::string> tokenize(const std::string& csvrow, char delim);
        int getNumberOfRows() override;
        std::vector<std::string> getRow(int index) override;

    private:
        std::istream *csv_file;
        std::vector<int> offsets;
        std::vector<int> lengths;
};
