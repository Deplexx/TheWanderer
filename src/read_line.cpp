#include "read_line.h"

#include <iostream>
#include <regex>

using std::cin;
using std::cout;
using std::sregex_token_iterator;
using std::regex;

const regex nws("\\S+");

vector<string> read_line() {
    string cmd_line;
    vector<string> ret;

    getline(cin, cmd_line);

    auto tokenizer_begin = sregex_token_iterator(cmd_line.begin(), cmd_line.end(), nws);
    auto tokenizer_end = sregex_token_iterator();

    for(auto s = tokenizer_begin; s != tokenizer_end; ++s)
        ret.push_back(s->str());

    return ret;
}