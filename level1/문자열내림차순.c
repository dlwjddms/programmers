#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
    return a>b;
}
string solution(string s) {
    string answer = "";
    vector <string> tmp ;
    for(int i =0 ;i< s.size(); i++){
        string _s_ = "";
        _s_ += s[i];
        tmp.push_back(_s_);
    }
    sort(tmp.begin(),tmp.end(),compare);
     for(int i =0 ;i< tmp.size(); i++)
         answer +=tmp[i];
    return answer;
}
