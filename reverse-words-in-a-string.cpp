//
// Created by daiyu on 2020/6/11.
//
#include "base.hpp"

string strReplace(string s)
{
    for(auto &c :s)
    {
        if(c == ' ')
            c = '_';
    }
    return s;
}
void printStr(const string& str)
{
    string tmp(strReplace(str));
    printf("size:%d, str:%s\n" ,str.size(), tmp.c_str());
}
class Solution {
public:
    string reverseWords(string& s) {
        stack<string> strStack;
        string str;
        for(auto c: s)
        {
            if(c == ' ')
            {
                strStack.push(str);
                str.clear();
            }
            else
            {
                str.push_back(c);
            }
        }
        strStack.push(str); //最后可能没有遇到空格

        string res;
        while(!strStack.empty())
        {
            str = strStack.top();
            printStr(str);
            if(str.size() >= 1)
            {
                res += str;
                res += ' ';
            }
            strStack.pop();
        }
        res.pop_back();
        return res;
    }
};

int main()
{
    Solution solution;
    string str("  hello world!  ");
    cout<<strReplace(solution.reverseWords(str))<<endl;
}
