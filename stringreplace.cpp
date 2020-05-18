#include <iostream>
#include <string>
#include <cstring>
using namespace std;


void stringReplace(string &src){
    int len = src.length();
    if(len <=0)
        return;

    int count=0;
    for(const auto x: src){
        if(x == ' ') 
        ++count;
    }
    int new_length = len + count*( strlen("%20") - strlen(" "));
    string tmp(new_length +1, '\0');
    for( int i=0, j=0; i<len; ++i){
        if(src[i]!=' '){
            tmp[j++]=src[i];
        }else{
            tmp[j++]='%';
            tmp[j++]='2';
            tmp[j++]='0';
        }
    }
    src.swap(tmp);

    return;
}

int main()
{
    string src = "we are happy";
    stringReplace(src);
    cout<<src<<endl;
    
}