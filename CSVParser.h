#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>

struct CSVParserStats {
    bool isFileOpen;
};

class CSVParser {

    public:
        CSVParser();
        ~CSVParser();
        void load(const std::string& file);
        CSVParserStats getStats() ;
        std::string readLine(int lineNumber);
        int getNoOfRows();
        std::string getValue(int row, int col);
        int getNoOfCols();
        int cols();
        int rows();

    private:
        std::ifstream csv_file; 
        std::string currentLine;
        int cols_;
        int rows_;
};

#endif
