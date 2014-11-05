#pragma once 

#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>

class CSVParser {

    public:
        CSVParser() {};
        ~CSVParser();
        void load(const std::string& file);
        std::string readLine(const int lineNumber);
        int getNoOfRows();
        std::string getValue(int row, int col);
        int getNoOfCols();
        int cols() const;
        int rows() const;

    private:
        std::ifstream csv_file; 
        int cols_;
        int rows_;
};
