#pragma once
#include <exception>

class FileTableException: public std::exception {
    public:
        FileTableException(const char* msg) : mMsg(msg) {}
        virtual ~FileTableException() throw() {}
        const char* what() const throw()  {return mMsg.c_str();}
    protected:
        std::string mMsg;
};
