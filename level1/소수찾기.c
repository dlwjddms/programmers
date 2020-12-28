
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*소수인지 확인한다.*/
bool check(int num){
    if(num ==2)
        return true;

    for(int i=2 ;i<num/2 +1 ;i++){
        if(num%i ==0)
            return false;
    }

    return true;
}
int solution(int n) {
    int answer = 0;

    /*  2부터 n까지 n-1개를 저장할 수 있는 배열 할당
        배열 참조 번호와 소수와 일치하도록 배열의 크기는
        n+1 길이만큼 할당(인덱스 번호 0과 1은 사용하지 않음) */
    bool* PrimeArray = new bool[n + 1];

    /*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌   */
    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true;

    /*  에라토스테네스의 체에 맞게 소수를 구함
        만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를
        가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
        PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
        소수가 아니게 된다. 그러므로 검사할 필요도 없다.
또한 i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2 에서 i*i로 개선할 수 있다.
    */
    for (int i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }
    /*전체 핑핑핑 돌면서 확인*/
    for(int i =2; i<=n; i++){
        if(PrimeArray[i])
            answer ++;
    }
    return answer;
}
