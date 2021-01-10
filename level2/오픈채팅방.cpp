#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#define ENTER 0
#define LEAVE 1
#define CHANGE 2
/*1.  이건 질문 봤음(1번빼고 다!! 어엄청 틀렸다) 
    : Enter [유저 아이디] [닉네임] 라고 했으므로 uid2234 자체가 유저아이디! 
      2234 라고 생각하면 엄청 틀린다!
  2.  시간 초과 (27번부터~31)
    : 1) erase 제거 해서 3개 줄임
      2) map 써야될것 같음

*/
    //vector<vector<string>> user;
    map< string, string > user;
string enter(string order){
    int idx= order.find(" ")+1;
    string uid="";
    string name="";
    string tmp = "";
    for(int i=idx; i<order.size();i++){
        tmp +=order[idx++];
        if(order[idx]==' '){
            uid +=tmp;
            tmp="";
            idx++;
            i++;
            continue;
        }
    }
    name +=tmp;
    if(user.find(uid) !=user.end()){
        
        return user.find(uid)->second;
    }
      
        user.insert(make_pair(uid,name));
            return name;
        
}
string leave(string order){
   
    string uid= order.substr(order.find(" ")+1,order.size());

    return user.find(uid)->second;

}
int check(string order){
    if(order.find("Enter")!=-1)
        return ENTER;
    else if(order.find("Leave")!=-1)
        return LEAVE;
    else if(order.find("Change")!=-1)
        return CHANGE;
    else
        return -1;
            
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=record.size()-1; i>=0;i--){
        string order = record[i];
        string name ;
        switch(check(order)){
            case ENTER : 
                 name = enter(order);
                 record[i] = name+"Enter"; 
                break;
            case CHANGE :
                name = enter(order);
                break;
            
            default : break;
        }
    }
    for(int i=0; i<record.size();i++){
        string order = record[i];
        string result;
        switch(check(order)){
            case ENTER :
                result =order.substr(0, order.find("Enter"));
                answer.push_back(result+"님이 들어왔습니다.");
                break;
            case LEAVE :                
                result = leave(order);
                answer.push_back(result+"님이 나갔습니다.");
                break;
            default : break;
        }
    }
   
    return answer;
}
