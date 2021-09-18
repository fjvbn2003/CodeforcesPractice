#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, h;
  cin>>n>>h;
  vector<int> up(n/2,0);
  vector<int> down(n/2,0);

  for(int i=0; i<n; i++){
    if(i%2==0){
      cin>> down[i/2];
    }else{
      cin>> up[i/2];
    } 
  }
  sort(up.begin(), up.end());
  sort(down.begin(), down.end());

  vector<int> intersect(h, 0);
  for(int i=0; i<h; i++){
    int b = n/2 -(lower_bound(down.begin(), down.end(), i) - down.begin());
    int u = n/2 -(lower_bound(up.begin(), up.end(), h-i+1) - up.begin());
    intersect[i] = b+u;
    //cout << "i: "<<i<<" b: "<<b<<" u: "<<u<<endl;
  }
  // for(int i=0; i<h ; i++){
  //   cout << intersect[i]<<" ";
  // }
  
  sort(intersect.begin(), intersect.end());
  cout << intersect[0]<<" ";
  cout << lower_bound(intersect.begin(), intersect.end(), intersect[0]+1) - intersect.begin()<<endl;
}