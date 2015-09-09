#include <set>
#include <exception>

class DuplicateException: public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Duplicate line detected";
    }
} dupEx;

class EmptyLineException: public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Empty line detected";
    }
} emptyEx;

class InvalidNumberOfColumns: public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Invalid number of columns detected";
    }
} invEx;

class Helper {
  public:
    void checkDuplicate(const std::string & input) {
        if(!aSet.insert(input).second) {
          throw dupEx;
        }
    }

    void checkEmpty(const std::string & input) {
        if(input.empty()) {
          throw emptyEx;
        }
    }

    void checkIfInvalidNumberOfColumns(const std::string & input, char delim, unsigned int expectedNumberOfCols) {
        size_t n = std::count(input.begin(), input.end(), delim);
        if(static_cast<unsigned int>(n) != expectedNumberOfCols - 1) {
            throw invEx;
        }
    }
private:
  std::set<std::string> aSet;
};
