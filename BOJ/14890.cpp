#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, l;
  cin>>n>>l;

  vector<vector<int> > arr(n, vector<int>(n,0));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin>> arr[i][j];
  int ans = 0;
  for(int i=0; i<n ; i++){
    // 행마다 판단.
    int cnt = 1;
    bool flag = true;
    for(int j=1; j<n; j++){
      if(arr[i][j-1]+1 == arr[i][j]){
          if(cnt>= l){
            cnt = 1;
          }else{
            flag = false;
            break;
          }
        
      }else if(arr[i][j-1] == arr[i][j]+1){
        if(cnt <0){
          flag = false;
          break;
        }
        cnt = -l+1;
      }else if(arr[i][j-1] == arr[i][j]){
        cnt++;
      }else{
        flag = false;
        break;
      }
    }
    if(cnt <0 || flag==false){
      continue;
    }else{
      ans++;
    }
  }
  for(int i=0; i<n ; i++){
    // 열마다 판단.
    int cnt = 1;
    bool flag = true;
    for(int j=1; j<n; j++){
      if(arr[j-1][i]+1 == arr[j][i]){
          if(cnt>= l){
            cnt = 1;
          }else{
            flag = false;
            break;
          }
      }else if(arr[j-1][i] == arr[j][i]+1){
                if(cnt <0){
          flag = false;
          break;
        }
        cnt = -l+1;
      }else if(arr[j-1][i] == arr[j][i]){
        cnt++;
      }else{
        flag = false;
        break;
      }
    }
    if(cnt <0 || flag==false){
      continue;
    }else{
      ans++;
    }
  }
  cout <<ans<<endl;
  return 0;
}