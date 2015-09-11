#pragma once

#include <set>
#include <algorithm>
#include <exception>
#include "HelperException.h"

class Helper {
  public:
    void checkDuplicate(const std::string & input) {
        if(!aSet.insert(input).second) {
          throw DuplicateException();
        }
    }

    void checkEmpty(const std::string & input) {
        if(input.empty()) {
          throw EmptyLineException();
        }
    }

    void checkIfInvalidNumberOfColumns(const std::string & input, char delim, unsigned int expectedNumberOfCols) {
        size_t n = std::count(input.begin(), input.end(), delim);
        if(static_cast<unsigned int>(n) != expectedNumberOfCols - 1) {
            throw InvalidNumberOfColumns();
        }
    }
private:
  std::set<std::string> aSet;
};
