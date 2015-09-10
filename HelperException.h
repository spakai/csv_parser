#pragma once
#include <exception>

class DuplicateException: public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Duplicate line detected";
    }
};

class EmptyLineException: public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Empty line detected";
    }
};

class InvalidNumberOfColumns: public std::exception
{
  public:
    virtual const char* what() const throw()
    {
      return "Invalid number of columns detected";
    }
};

