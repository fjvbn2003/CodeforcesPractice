#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  vector<int> arr2;
  
  for(int i=0; i<n; i++)
    cin>> arr[i];
  arr2 = arr;
  vector<pair<int, int> > ans;
  vector<pair<int, int> > ans2;

  // 왼쪽에서 오른쪽 그리디로 수정.
  // 오른쪽에서 왼쪽으로 그리디로 수정.

  //왼쪽에서 오른쪽으로
  for(int i=0; i<n; i++){
    // 가능하다면 현재 값을 줄여보기. 
    if( i != n-1 && arr[i+1]<arr[i]){
      if(i ==0){
        arr[i] = 1;
        ans.push_back({i+1, arr[i]});
      }else{
        if(arr[i-1]<=arr[i+1]){
          arr[i] = arr[i-1];
          ans.push_back({i+1, arr[i]});
        }
        // 바꾸지 못했다면 현재 값을 늘리는 방향으로.
      }
    }
    // 현재값을 줄이는 것이 안된다면 현재 값을 늘리기.
    if(i !=0 && arr[i]< arr[i-1]){
      arr[i] = arr[i-1];
      ans.push_back({i+1, arr[i]});
    }
    if(ans.size()>3){
        break;
    }
  }
  // 오른쪽에서 왼쪽으로
  for(int i=n-1; i>=0; i--){
    // 자신을 늘려본다.
    if(i != 0  && arr2[i] < arr2[i-1]){
      if(i== n-1){
        arr2[i] = 1000000000;
        ans2.push_back({i+1, arr2[i]});
      }else{
        if( arr2[i+1]>= arr2[i-1]){
          arr2[i] = arr2[i+1];
          ans2.push_back({i+1, arr2[i]});
        }
      }
    }
    // 자신을 줄인다.
    if(i != n-1 && arr2[i]> arr2[i+1]){
      arr2[i] = arr2[i+1];
      ans2.push_back({i+1, arr2[i]});
    }
    if(ans2.size()>3){
      break;
    }
  }
  // 만약 왼쪽 -> 오른쪽 , 오른쪽 -> 왼쪽 둘 다 안된다면, 포기.
  if(ans.size()>3 && ans2.size()>3){
    cout << "NO"<<endl;
  }else{
    // 둘 중 하나라도 성공했다면 정답 출력.
    if(ans.size()<=3){
      cout <<"YES"<<endl;
      cout <<ans.size()<<endl;
      for(int i=0; i<ans.size(); i++){
        cout << ans[i].first <<" "<<ans[i].second<<endl;
      }
    }else if( ans2.size() <=3){
      cout <<"YES"<<endl;
      cout <<ans2.size()<<endl;
      for(int i=0; i<ans2.size(); i++){
        cout << ans2[i].first <<" "<<ans2[i].second<<endl;
      }

    }
  }
  return 0;
}