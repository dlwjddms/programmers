#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int m) {
    long long k = (long long)m;
    long long count =0;
   if (number.length() <= k) return "";
    for(long long i=0; i<k;i++){
        for(long long j=0; j<number.size();j++){
            if(count >=k)
                return number;
            if(number[j]<number[j+1]){
                number.erase(number.begin()+j,number.begin()+j+1);
                count++;
                j--;
                //-----j를 두번~----
                j--;
                
            }
            if(j==number.size()-1){
                 number.erase(number.begin()+j,number.begin()+j+1);
                count++;
                break;
            }
             //----맨뒤를 이때 지워~~~ 이 바보야~~~-----
        }
    }
    
    for(long long i=0 ; i<k-count;i++){
       // cout << number <<"\n";
        number.erase(number.begin()+number.size()-1,number.begin()+number.size());
    }
    return number;
}
