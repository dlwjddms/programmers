#include <string>
#include <vector>

using namespace std;
string weeks[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
string solution(int a, int b) {
    string answer = "";
    int date = 1;     // staring from 1 
    int week_idx = 5; // starting from friday
    /*match the month*/
    for(int i =1; i<a ; i++){ // iterating with month
        int rest = months[i-1]%7; // find the rest of the month 
        week_idx = (week_idx+rest)%7; // when is the next month 1st day~?
    }
    
    /*match the week*/
    while(b-date > 7){ 
        date += 7;
    }
    /*match the day*/
    int rest = b-date;
    week_idx = (week_idx+rest)%7;
    
    answer = weeks[week_idx];
    
    return answer;
}
