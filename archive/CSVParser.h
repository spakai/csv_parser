#pragma once 

#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>

#include "GetLineTokenizer.h"

using namespace std;

class CSVParser {

    public:
        CSVParser(Tokenizer & tokenizer);
        ~CSVParser() {};
        void load(const string& file);
        string readLine(const int lineNumber);
        int getNoOfRows();
        string getValue(int row, int col);
        int getNoOfCols();
        int cols() const;
        int rows() const;

    private:
        ifstream csv_file; 
        Tokenizer & tokenizer;
        int cols_;
        int rows_;
};
