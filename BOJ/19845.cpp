#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int N, Q;


  cin>>N>>Q;
  vector<int> arr(N);
  vector<int> arr2;
  
  for(int i=0; i<N; i++)
    cin>> arr[i];
  
  arr2 = arr;
  sort(arr2.begin(), arr2.end());
  vector<pair<int, int> > lasers(Q, pair<int, int>());
  for(int i=0; i<Q; i++){
    cin>> lasers[i].first>> lasers[i].second;
  }
  for(int i=0; i<Q; i++){
    int x = lasers[i].first;
    int y = lasers[i].second;
    // 위로
    int ans = 0;
    if(y>N) ans = 0;
    else{
      // max_y를 찾는다.
      int max_y = N-(lower_bound(arr2.begin(), arr2.end(), x)-arr2.begin());

      ans += max(0, max_y-y);
      ans += max(0,(arr[y-1]-x));
      if(y>max_y)  ans = 0;
      else{
        ans +=1;
      }
      
    }

    cout <<ans<<"\n";
  }
  return 0;
}