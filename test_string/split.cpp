//
// Created by xuan on 2016/8/31.
//
#include "split.h"
#include <vector>
#include <cctype>

using std::string;
using std::vector;

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
    while (i != s.size()) {
        //找到第一个非空字符
        while (i != s.size() && isspace(s[i])) {++i;}

        string_size j = i;
        //找到i后面第一个空字符
        while (j != s.size() && !isspace(s[j])) {++j;}
        if (j != i) {
            ret.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return ret;
}
