#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;
// 누적합을 해서 각각의 구간마다 표준편차를 구함.
// 시간복잡도 n^3


int main(){
  //freopen("./input.txt", "r", stdin);
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++)
    cin>> arr[i];
  //cout <<"hi"<<endl;

  // 누적 합.
  vector<int> acc(n, 0);
  acc[0] = arr[0];
  for(int i=1; i<n; i++)
    acc[i] = acc[i-1]+ arr[i];
  
  vector<int> ans(n, 0);
  for(int i=0; i<n; i++){
    //cout <<"hi"<<endl;

    if((i==0) || (i == n-1)){
      ans[i] = 1;
      continue;
    }

    // 반복
    int m_idx = 0;
    double m_std = -1;
    for(int j=0; j<n-i; j++){
        double s = acc[j+i];
        if(j !=0){
          s-= acc[j-1];
        }
        // s는 평균
        s/=(i+1);
        double tmp_std = 0;
        for(int k=j; k<=j+i; k++){
          tmp_std += pow(abs((double)arr[k]-s),2);
        } 
        //cout << "i: "<<i <<" j:"<<j<<" tmp_std:"<<tmp_std<<endl;
        if(m_std < tmp_std){
          m_idx = j;
          m_std = tmp_std;
        }
    }
    ans[i] = m_idx+1;
  }
  for(int i=0; i<n; i++){
    cout <<ans[i]<<endl;
  }
  return 0;
}