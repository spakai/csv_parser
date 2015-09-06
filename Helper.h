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

template <typename T>
class Helper {
public:
  void checkDuplicate(T & input) {
      if(!aSet.insert(input).second) {
        throw dupEx;
      }
  }

private:
  std::set<T> aSet;
};
