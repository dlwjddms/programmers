#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int y_num =0, p_num = 0;
    for(int i=0; i< s.size(); i++){
        if(s[i]=='y'||s[i]=='Y')
             y_num++;
        else if(s[i]=='p'||s[i]=='P')
             p_num++;
    }
    
    return y_num == p_num ? true : false;
}
