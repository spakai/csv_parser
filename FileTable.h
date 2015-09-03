#pragma once

#include "Table.h"
#include <sstream>

class FileTable : public Table{
    public:
        FileTable() {};
        ~FileTable() {};
        void init(const std::string& filename);
        void init(std::ifstream); 
        std::vector<std::string> tokenize(const std::string& csvrow, char delim);
        virtual int getNumberOfRows();
        virtual std::vector<std::string> getRow(int index);
};
