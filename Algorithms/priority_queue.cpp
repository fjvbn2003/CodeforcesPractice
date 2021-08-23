#include <iostream>
#include <queue>
#include <vector>


using namespace std;

struct my_st{
  int cost;
  int to;
};
struct comp{
  bool operator()(const my_st& a, const my_st&b){
  return a.cost>b.cost;
  }
};


int main(){

  priority_queue<my_st, vector<my_st>, comp>pq;
  my_st st;
  st.cost = 1;
  st.to = 2;
  pq.push(st);
  st.cost = 10;
  st.to = 7;
  pq.push(st);
  st.cost = 5;
  st.to = 7;
  pq.push(st);
  st.cost = 2;
  st.to = 7;
  pq.push(st);
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    cout <<cur.cost<<" "<<cur.to<<endl;
  }
  return 0;
}