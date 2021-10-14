#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int test_case;
  cin>> test_case;
  while(test_case--){
    int n, k;
    cin>>n>>k;
    vector<int> mice(k);
    for(int i=0; i<k; i++)
      cin>>mice[i];
    sort(mice.begin(), mice.end());
    //이분 탐색을 위한 backsum
    vector<long long> back_sum(k, 0);
    back_sum[0] = (n-mice[k-1]);
    for(int i=k-2; i>=0; i--){
      back_sum[k-i-1] = back_sum[k-i-2]+(n-mice[i]);
    }
    // for debugging
    // for(int i=0; i<k; i++){
    //   cout << back_sum[i]<<" ";
    // }
    // cout <<endl;
    



    int max_cnt = -1;
    for(int i=0; i<mice.size(); i++){
      // i번째 쥐를 살릴 때.
      int remain_time = mice[i];
      int cnt;
      if(mice[i] != mice.back())
        cnt = lower_bound(back_sum.begin(), back_sum.begin()+(k-i-1), remain_time) - back_sum.begin();
      else
        cnt = 0;
      // cout <<"remain_time: "<<remain_time<<endl;
      // cout << i<< " 번 쥐를 살릴 때   살릴 수 있다.: "<< cnt<<endl; 
      // int cnt =1;
      // for(int j=0; j<(k-i-1); j++){
      //   if(back_sum[j]<=remain_time){
      //     cnt++;
      //   }else{
      //     break;
      //   }
      // }

      max_cnt = max(max_cnt, cnt+1);
    }
    cout << max_cnt<<endl;
  }
  return 0;
}