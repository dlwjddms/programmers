#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool minus =false, plus =false;
    // 음수 check
    if(s[0]=='-'){
        minus = true;
       
    }
    //양수 check
    else if(s[0]=='+')
         plus =true;
    
    for(int i=0; i<s.size();i++){
        // 자리 수를 옮겨준다
        answer=answer*10;
        //부호 지나친다
        if(i==0&&(minus||plus))
            continue;
        // char -> int
        answer += s[i]-'0';
      
    }
    if(minus)
        answer=answer *-1;
    return answer;
}
