#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;
void pop_min_queue(priority_queue<int>& q) {
    vector<int> tmp ;
    while(!q.empty()) {
        if(q.size()>1)
            tmp.push_back(q.top());
        q.pop();
    }
    for(int i=0; i<tmp.size();i++){
        q.push(tmp[i]);
    }
   return ;
}
int get_num(string num){
    int ret =0;
    string tmp="";
    for(int i=2; i<num.size();i++){
        tmp+=num[i];
    }
    ret = stoi(tmp);
    return ret;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> q;
    for(int i=0; i<operations.size();i++){
        if(operations[i][0]=='I'){//I
            int num = get_num(operations[i]);
            q.push(num);
        }else if(operations[i]=="D 1"){//D1
          //  cout << q.top();
            if(!q.empty())
               q.pop();
           
        }else{//D-1
             pop_min_queue(q); 
        }
    }
  
    if(q.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(q.top());
        while(!q.empty()) {
            if(q.size()==1)
                answer.push_back(q.top());
            q.pop();
         }
    }
    return answer;
}
