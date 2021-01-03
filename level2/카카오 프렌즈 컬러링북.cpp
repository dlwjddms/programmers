#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*전에 봤던 위치부터 찾아 나가려고 했는데 그렇게 하면 이상 해질 거라는 생각을 못했다 나는 바보였다~!*/
vector<int> find_next_start(vector<vector<int>> visit,vector<int> location,vector<vector<int>> picture){
    for(int i=location[0];i<visit.size();i++){
         for(int j=0;j<visit[0].size();j++){
             if(visit[i][j]==0&&picture[i][j]!=0){
                 location[0]=i;
                 location[1]=j;
                 return location;
             }
         }
    }
    location[0] =-1;
    return location;
}
int find_same_area(vector<int> location,vector<vector<int>> & visited,vector<vector<int>> picture){
    int count=1;
    int x=location[0];
    int y= location[1];
    visited[x][y] =1;
    //up
    if(y>0&&visited[x][y-1]==0&&picture[x][y]==picture[x][y-1]){
         location[1] -=1;
         count +=find_same_area(location,visited,picture);
         location[1] +=1;
    }
    // right
    if(x<picture.size()-1&& visited[x+1][y]==0&&picture[x][y] ==picture[x+1][y]){
        location[0] +=1;
        count +=find_same_area(location,visited,picture);
        location[0] -=1;
    }
    //left
    if(x>0&&visited[x-1][y]==0&&picture[x][y] ==picture[x-1][y]){
        location[0] -=1;
        count +=find_same_area(location,visited,picture);
        location[0] +=1;
    }
    // below
    if(y<picture[0].size()-1&&visited[x][y+1]==0&&picture[x][y]==picture[x][y+1]){
         location[1] +=1;
         count +=find_same_area(location,visited,picture);
         location[1] -=1;
    }
    
    return count;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<int> answer(2);
    vector<int> location(2,0);
    vector<int> area_size;
    vector<vector<int>> pic = picture;
  
   location = find_next_start(visited,location,pic);

   while(location[0] != -1){
      // cout<<location[0]<<":"<<location[1]<<"\n";
        area_size.push_back(find_same_area(location,visited,pic));
        location = find_next_start(visited,location,pic);
    } 
 
    if(area_size.size()){
        sort(area_size.begin(),area_size.end());
         max_size_of_one_area = area_size[area_size.size()-1];
    }else
        max_size_of_one_area=0;
    number_of_area = area_size.size();

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
