#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int idx = -1;

bool sort_str(string a, string b){
    /*sort using idx*/
    if(a[idx]>b[idx])
        return false;
    else if (a[idx]<b[idx])
         return true;
    else // if same just comapre whole string
        return a>b ? false : true; 
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    sort(strings.begin(), strings.end(),sort_str);
    answer = strings;
    return answer;
}
