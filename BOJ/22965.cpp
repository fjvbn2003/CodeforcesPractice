#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++)
    cin>>arr[i];
  vector<int> tmp = arr;
  sort(tmp.begin(), tmp.end());
  unordered_map<int, int> m;
  for(int i=0; i<tmp.size(); i++){
    m.insert({tmp[i],i});
  }
  // 배열압축 0~(n-1)
  for(int i=0; i<arr.size(); i++){
    arr[i] = m[arr[i]];
  }
  int before = arr[0];
  int cnt = 0;
  for(int i=1; i<arr.size(); i++){
    // 만약 현재 값이 before 다음이 아니라면 cnt 증가.
    if(arr[i] != before+1){
      cnt++;
    }
    before = arr[i];
  }
  if(cnt==0){
    cout <<1<<endl;
  }else if(cnt==1){
    cout <<2<<endl;
  }else{
    // 배열을 3개로 쪼개면 어떤 원소든 자유롭게 이동가능.
    cout <<3<<endl;
  }
  return 0;

}