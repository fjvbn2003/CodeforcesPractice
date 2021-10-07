#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
// 처음에 입장 순서로 정렬 & priority quque로 비어있는 위치 실시간 계산 -> 비어있는 자리가 여러개일 때 빨리 끝난쪽으로 가게됨 -> WA
// 현재 시작시간보다 작은 것들을 전부 꺼내서 가장 번호가 작은 것만 꺼내고, 다시 집어넣는 방향 -> TLE
// 어떤 방식 좋을까?
// set을 하나 두어서 매번 정렬하지 말고, 전부다 넣는다.
using namespace std;

int main(){

  int n; 
  cin>>n;
  int start, finish;
  int cnt = -1;
  priority_queue<pair<int, int>  >pq;
  vector<int> ans(n, 0);
  vector<pair<int, int> > arr;
  set<int> st;
  for(int i=0; i<n; i++){
    cin>> start>> finish;
    arr.push_back({start, finish});
  }
  sort(arr.begin(), arr.end());

  for(int i=0; i<n; i++){
    start = arr[i].first;
    finish  = arr[i].second;
    while(!pq.empty() && -pq.top().first <=start){
      st.insert(pq.top().second);
      pq.pop();   
    }
    if(st.empty()){
      // 컴퓨터 한 대 생성.
      cnt++;
      ans[cnt]++;
      pq.push({-finish, cnt});
      continue;
    }else{
      auto idx = st.begin();
      ans[*idx]++;
      pq.push({-finish, *idx});
      st.erase(idx);
    }

    //cout << "out is: "<< out.second<<" out time: "<<-out.first<<" in time: "<<start<<endl;
    
  }

  cout << cnt+1<<endl;
  for(int i=0; i<cnt+1; i++){
    cout <<ans[i]<<" ";
  }
  cout <<endl;
  return 0;
}
/*
10
10 100
20 50
30 120
60 110
93 105
95 130
110 128
122 500
129 300
140 150

*/
