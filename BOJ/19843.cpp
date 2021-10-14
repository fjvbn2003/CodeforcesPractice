#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
// Union Find, Minimum Spanning Tree, Segment Tree, nCm, treap
// 과 같은 고급 자료구조도 공부하기 with 종만북.
// BOJ 19843 수면패턴.
// 알고리즘을 열심히 공부하는 이유.
// 알고리즘 문제를 잘 푼다는 것은 -> 논리적으로 생각하고 그것이 잘 맞아떨어진다는 것이 아닐까?
// 실수없이 빠르게 프로그래밍 하는 능력을 나타내기도 한다.
// 내가 푼 문제를 논리적으로 잘 설명할 수 있다면 더더욱 협업을 잘하는 인재일 것이다.
// 따라서 알고리즘이 프로그래밍의 전부는 아니지만 문제해결력의 지표로서는 매우 설득력있는 지표라고 생각한다.
// 그러므로 알고리즘 공부를 열심히 할 것이다.
// C++ 이외에도 파이썬과 JAVA를 사용해서 문제를 많이 풀어보자.

// 내가 생각하고 있다는 것을 인지하는 능력(메타인지)
// 생각의 생각. 논리적인가?를 끊임없이 생각할 것.
// 이제는 연습문제가 대회 즉 실전이라고 생각하고 문제를 풀어보자.(shake, 삼성 코테준비)
using namespace std;

int main(){
  int T, N;
  unordered_map<string, int> um;
  um.insert({"Mon", 1});
  um.insert({"Tue", 2});
  um.insert({"Wed", 3});
  um.insert({"Thu", 4});
  um.insert({"Fri", 5});
  
  cin>>T>>N;
  int sleep_time=0;
  for(int i=0; i<N; i++){
    string d1,d2;
    int h1,h2;
    cin>>d1>>h1>>d2>>h2;
    if(d1==d2){
      sleep_time += h2-h1;
    }else{
      sleep_time += (um[d2]-um[d1]-1)*24+(24-h1)+h2;
    }
    //cout <<"i:"<<i<<" "<<sleep_time<<endl;
  }
  if(T<=sleep_time){
    cout <<0<<endl;
  }else{
    if(T-sleep_time >48){
      cout <<-1<<endl;
    }else{
      cout << T-sleep_time<<endl;
    }
  }
  return 0;

}