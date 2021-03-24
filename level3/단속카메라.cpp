#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 1;
   
    sort(routes.begin(),routes.end(),cmp);
    
    
    for(int i=0; i<routes.size();i++){
        bool chk = false;
         int min_end = routes[i][1];
         for(int j=0; j<routes.size();j++){
             if(min_end<routes[j][0]){
                 chk =true;
                 answer ++;
                 i=j-1;
                 break;
             }
        }
        if(chk ==false)
            break;
    }
    return answer;
}
