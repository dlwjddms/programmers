#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check_dup(vector<int> number, int n){
    
    for(int i=0; i<number.size();i++){
        if(number[i]==n)
            return true;
    }
    return false;
}
/*add two number while iter*/
vector<int>find_arr(vector<int> numbers){
    vector<int> answer;
    for(int i =0 ; i< numbers.size(); i++){
        for(int j =i+1 ; j< numbers.size();j++){
            int num = numbers[i]+numbers[j];
            /*check if num is already in the vector answer*/
            bool check = check_dup(answer, num);
            if(check == false)
                answer.push_back(num);
        }
    }
    return answer;
}
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    answer = find_arr(numbers);
    sort(answer.begin(),answer.end());
    return answer;
}
