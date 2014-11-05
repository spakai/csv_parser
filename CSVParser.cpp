#include "CSVParser.h"

CSVParser::CSVParser() { }

CSVParser::~CSVParser() {
    csv_file.clear();
    csv_file.close();
}

int CSVParser::rows() const {
    return rows_;
} 

int CSVParser::cols() const {
    return cols_;
}

void CSVParser::load(const std::string& filename) {
    csv_file.exceptions ( std::ifstream::failbit | std::ifstream::badbit ); 
    csv_file.open(filename);
    cols_ = getNoOfCols();
    rows_ = getNoOfRows();
}

CSVParserStats CSVParser::getStats() {
    CSVParserStats stats;
    stats.isFileOpen = csv_file.is_open();
    return stats;
}

std::string CSVParser::readLine(const int lineNumber) {

    try {
        std::string currentLine;
        csv_file.clear();
        csv_file.seekg(0, std::ios::beg);
        for (int i{0}; i < lineNumber ; i++) { 
            std::getline(csv_file, currentLine);
        }

        return currentLine;

    } catch (...) {
        if (csv_file.eof()) {
            throw std::out_of_range("index out of range");
        } else {
            throw;
        }
    } 
}

int CSVParser::getNoOfRows() {
   int lines{0};
 
    try {
        std::string currentLine;
        csv_file.clear();
        csv_file.seekg(0, std::ios::beg);
        while(!csv_file.eof()) {
            std::getline(csv_file, currentLine);
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
    std::string rowstr = readLine(1);
    int cols{1};
    
    for (auto it = rowstr.begin(); it < rowstr.end(); ++it) {
        if ((*it) == ',') {
            ++cols;
        } 
    }

    return cols;

}

std::string CSVParser::getValue(int row, int col) {
    std::string rowstr = readLine(row);
    std::string colstr;
    int count{0};

    if (col == cols_) {
        for(std::string::reverse_iterator rit = rowstr.rbegin();; ++rit) {
            if((*rit) == ',') break;
            colstr+= *rit;
        }
    } else {
        std::string::iterator end = rowstr.end();

        for (std::string::iterator it = rowstr.begin();; ++it)  {

            if (it == end || col == 0) 
                throw std::out_of_range("index out of range");

            if ((*it) == ',')  {
                if ( ++count == col)  {
                    break;
                } else {
                    continue;
                }
            }

        colstr += *it;
        }

    }

    return colstr;
}
