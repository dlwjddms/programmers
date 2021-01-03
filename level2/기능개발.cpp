#include <string>
#include <vector>

using namespace std;
int pop_out(vector<int> prog){
    int count =0;
    for(int i=0; i<prog.size();i++){
        if(prog[i]<100)
            break;
        count ++;
    }
    return count;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(progresses.size()){
        for(int i=0; i<progresses.size();i++){
            /*진행 상태 추가*/
            progresses[i] += speeds[i];
        }
        /*다 추가 헀으니 검사*/
        if(progresses[0]>=100){        
                    int ans = pop_out(progresses);
                    answer.push_back(ans);
                    progresses.erase(progresses.begin(),progresses.begin()+ans);
                    speeds.erase(speeds.begin(),speeds.begin()+ans);
         }
    }
    return answer;
}
