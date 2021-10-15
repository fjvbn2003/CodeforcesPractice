#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  vector<vector<int> > arr(N, vector<int>(3));
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      cin>> arr[i][j];
    }
  }
  int mini = 1234567890;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      for(int k=0; k<N; k++){
        int tmp = 0;
        for(int l=0; l<N; l++){
          if(arr[l][0]<= arr[i][0] && arr[l][1]<= arr[j][1] && arr[l][2] <= arr[k][2])
            tmp++;
        }
        if(tmp >=K){
          mini = min(mini, arr[i][0]+arr[j][1]+arr[k][2]);
        }

      }
  cout <<mini<<endl;
  return 0;
}