#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*밑에 어떤 부분이 왜 되는지 알수 없다*/
bool compare(vector<float>a,vector<float>b){
    if(a[1]>b[1])
        return true;
    /*이게 필요한 행위였음*/
    else if(a[1]==b[1]){
        if(a[0]<b[0])
            return true;
        else
            return false;
    }
        return false;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    //vector < vector <int> > v(10,vector <int>(10,0));
    vector<vector<float>> stage(N,vector <float>(2,0.0));
    for(int i=0;i<stages.size();i++){
        if(stages[i]<N+1){
         stage[stages[i]-1][1] +=1.0;
        }
    }
    int people = stages.size();
    for(int i=0 ; i<stage.size();i++){
        stage[i][0] = i+1;
        int stage_people =  stage[i][1] ;
        /*이게왜 문제가 되는지 알수 없다*/
        if(stage[i][1]!=0)
            stage[i][1] = stage[i][1]/people;
        people -=stage_people;
    }
    sort(stage.begin(),stage.end(),compare);
    
    for(int i=0;i<stage.size();i++){
        answer.push_back(stage[i][0]);
    }
    return answer;
}
