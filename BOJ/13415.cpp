// 내가 생각하고 있는 것에 대해 생각하는 것.
// 제 3자의 눈으로 나의 논리를 보기.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(const int a, const int b){
  return a>b;
}
int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int N,K;
  cin>>N;
  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin>> arr[i];
  
  cin>>K;
  
  vector<pair<int, int> > sort_pair(K, pair<int, int>());
  for(int i=0; i<K; i++){
    cin>> sort_pair[i].first>>sort_pair[i].second;
  }

  int maxi = max(sort_pair[0].first, sort_pair[0].second);
  sort(arr.begin(), arr.begin()+sort_pair[0].first);
  sort(arr.begin(), arr.begin()+sort_pair[0].second, comp);

  int last_sort = 0;
  for(int i=1; i<K; i++){
    // 정렬을 최대한 미룬다.
    if(maxi <= sort_pair[i].first || maxi<= sort_pair[i].second){
      maxi = max(sort_pair[i].first, sort_pair[i].second);
    }else{
    // 작아졌을 때 한번에 정렬.
    //cout <<"sort at: "<<i<<endl;
      sort(arr.begin(), arr.begin()+sort_pair[i-1].first);
      sort(arr.begin(), arr.begin()+sort_pair[i-1].second, comp);
      maxi = max(sort_pair[i].first, sort_pair[i].second);
      last_sort = i-1;
    }
  }
  
    sort(arr.begin(), arr.begin()+sort_pair[K-1].first);
    sort(arr.begin(), arr.begin()+sort_pair[K-1].second, comp);
    
  for(int i=0; i<N; i++){
    cout <<arr[i]<<" ";
  }
  cout <<endl;
  return 0;
}
