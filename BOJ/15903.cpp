#include <iostream>
#include <queue>
using namespace std;
// 우선순위 큐 이용. 그리디로 가장 작은 것 두개를 연산.
int main(){
  int n, m;
  cin>>n>>m;
  priority_queue<long long> pq;
  long long t,a,b;
  for(int i=0; i<n; i++){
    cin>>t;
    pq.push(-t);
  }
  for(int i=0; i<m; i++){
    a = -pq.top();
    pq.pop();
    b = -pq.top();
    pq.pop();
    pq.push(-(a+b));
    pq.push(-(a+b));
  }
  long long ans = 0;
  while(!pq.empty()){
    ans += -pq.top();
    pq.pop();
  }
  cout <<ans<<endl;
  return 0;

}