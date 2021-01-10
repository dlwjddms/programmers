#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

int solution(int n) {
    int answer = 0;
    vector <string> num ;
    int cnt =0;
    int copy =n;
    string cmp ="";
      while(copy>0){  
         if(copy%2)
             cnt ++;
         copy=copy/2;
        }
     while(1){
         n++;
         copy =n;
         int copy_count =0;
         while(copy>0){  
         if(copy%2)
             copy_count ++;
         copy=copy/2;
        }
         if(cnt == copy_count)
             return n;
     }
