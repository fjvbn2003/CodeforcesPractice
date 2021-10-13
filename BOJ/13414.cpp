#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
// unordered map을 사용하여 배열의 뒤에서부터 탐색.
int main(){
  int K, L;
  cin>>K>>L;
  vector<string> arr(L);
  for(int i=0; i<L; i++){
    cin>> arr[i];
  }
  unordered_map<string, int> um;
  vector<string> cand;
  for(int i=L-1; i>=0; i--){
    if(um.find(arr[i]) == um.end()){
      cand.push_back(arr[i]);
      um.insert({arr[i], 1});
    }
  }
  int cnt = 0;
  for(int i=cand.size()-1; i>=0; i--){
    cout << cand[i]<<"\n";
    cnt++;
    if(cnt >=K){
      break;
    }
  }
  return 0;
}