#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int left =0;
    int right =0;
    for(int i=0; i<s.size();i++){
        if(s[i]=='(')
            left++;
        else
            right++;
        if(left<right)
            return false;
    }
     if(left!=right)
            return false;

    return true;
}
