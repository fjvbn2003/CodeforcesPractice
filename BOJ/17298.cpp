#include <iostream>
#include <vector>
#include <stack>
/*
문제: 오큰수(17298 번)
*/

using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++)
    cin>> arr[i];
  stack<int> st;
  vector<int> ans;
  for(int i=n-1; i>=0; i--){
    if(st.size() ==0){
      ans.push_back(-1);
      st.push(arr[i]);
    }else{
      while(st.size() && st.top()<=arr[i]){
        st.pop();
      }
      if(st.size()==0){
        ans.push_back(-1);
        st.push(arr[i]);
      }else{
        ans.push_back(st.top());
        st.push(arr[i]);
      }
    }
  }
  for(int i=ans.size()-1; i>=0; i--){
    cout << ans[i]<<" ";
  }
  cout <<endl;
  return 0;

}