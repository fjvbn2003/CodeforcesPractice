#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int N, M, L;

vector<int> arr;

int ans;
// brute force & back-tracking(ans 사용) -> 시간초과.
void brute(int idx, int remain, int before, int best_min){
  //cout <<"idx :"<<idx<<" remain:"<<remain<<" best_min:"<<best_min<<endl;
  if(remain==1){
    int cand = arr[idx] - before;
    int cand2 = L-arr[idx];
    best_min = min(best_min, cand);
    best_min = min(best_min, cand2);
    ans = max(ans, best_min);
    //cout <<"terminate ans: "<<ans<<endl;
    return;
  }
  int cand = arr[idx] - before;
  if(best_min > cand){
    best_min = cand;
  }
  // back-tracking
  //if(best_min < ans) return;
  for(int i=idx+1; i<M; i++){
    //if(arr[i]- arr[idx] < ans ) continue;
    brute(i, remain-1, arr[idx], best_min);
  }
  return;
}
int main(){
  cin>>N>>M>>L;
  arr.resize(M, 0);
  for(int i=0; i<M; i++){
    cin>>arr[i];
  }
  int t;
  ans = -1;
  for(int j=0; j<M; j++)
    brute(j, M, 0, arr[j]);
  for(int i=0; i<N; i++){
    cin>>t;

    cout <<ans<<endl;
  }
  return 0;
}