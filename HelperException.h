#pragma once
#include <exception>

class HelperException: public std::exception {
    public:
        HelperException(const char* msg) : mMsg(msg) {}
        virtual ~HelperException() throw() {}
        const char* what() const throw()  {return mMsg.c_str();}
    protected:
        std::string mMsg;
};

class DuplicateException: public HelperException
{
  public:
		DuplicateException() : HelperException("Duplicate line detected") {};
};

class EmptyLineException: public HelperException
{
	public:
		EmptyLineException() : HelperException("Empty line detected") {};
};

class InvalidNumberOfColumns: public HelperException
{
  public:
		InvalidNumberOfColumns() : HelperException("Invalid number of columns detected") {};
};
