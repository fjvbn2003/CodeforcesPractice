#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++)
    cin>> arr[i];
  sort(arr.begin(), arr.end());
  for(int time = 0; time<n+1; time++){
    for(int i=n-1; i>0; i--){
      if(arr[i]== arr[i-1]+1){
        swap(arr[i], arr[i-1]);
      }
    }
  }
  for(int i=0; i<n; i++){
    cout <<arr[i]<<" ";
  }
  cout <<endl;
  return 0;

}