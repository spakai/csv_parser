#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <regex>
#include <iostream>


using namespace std;

class Tokenizer {

    public:
        Tokenizer(string& row);
        ~Tokenizer() {};
        string& operator[] (int i);

    private:
        vector<std::string> tokens;
};
