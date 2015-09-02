#include "CSVParser.h"
#include "Tokenizer.h"


CSVParser::CSVParser(Tokenizer & tokenizer) 
    :tokenizer(tokenizer)
{
}

int CSVParser::rows() const {
    return rows_;
} 

int CSVParser::cols() const {
    return cols_;
}

void CSVParser::load(const string& filename) {
    csv_file.exceptions ( ifstream::failbit | ifstream::badbit ); 
    csv_file.open(filename);
    cols_ = getNoOfCols();
    rows_ = getNoOfRows();
}

string CSVParser::readLine(const int lineNumber) {

    try {
        string currentLine;
        csv_file.clear();
        csv_file.seekg(0, ios::beg);
        for (int i{0}; i < lineNumber ; i++) { 
            getline(csv_file, currentLine);
        }

        return currentLine;

    } catch (...) {
        if (csv_file.eof()) {
            throw out_of_range("index out of range");
        } else {
            throw;
        }
    } 
}

int CSVParser::getNoOfRows() {
   int lines{0};
 
    try {
        string currentLine;
        csv_file.clear();
        csv_file.seekg(0, ios::beg);
        while(!csv_file.eof()) {
            getline(csv_file, currentLine);
            ++lines;
        } 
    } catch (...) {
        if (!csv_file.eof()) {
            throw;
        }

    }

    return lines;
}

int CSVParser::getNoOfCols() {
    string rowstr = readLine(1);
    tokenizer.tokenize(rowstr);
    return tokenizer.size();
}

string CSVParser::getValue(int row, int col) {
    string rowstr = readLine(row);
    tokenizer.tokenize(rowstr);
    return tokenizer[col];
}
