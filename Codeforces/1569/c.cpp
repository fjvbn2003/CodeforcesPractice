#include <iostream>
#include <queue>
using namespace std;

int main(){
  queue<int> q;
  q.push(1);
q.push(1);
q.push(1);
q.push(1);
q.push(1);
  for(int i=0; i<q.size(); i++){
    cout << q.front()<<endl;
    q.pop();
    q.push(2);
  }
  return 0;
}