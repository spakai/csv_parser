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

private:
  std::set<std::string> aSet;
};
