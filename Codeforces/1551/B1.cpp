#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

int main(){
  int test_case;
  cin>> test_case;
  string s;
  while(test_case--){
    int n,k;
    cin>> n >>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
      cin>>arr[i];
    map<int,int> m;
    for(int i=0; i<arr.size(); i++){
      if(m.count(arr[i]) ==0)
        m[arr[i]] = 1;
      else{
        m[arr[i]]++;
      }
    }
    int real_k = k;
    for(auto it = m.begin(); it!=m.end() ; it++){
      it->second  = (it->second/real_k)*(it->second);
    }
    for(int i=0; i<n; i++){
      if(m[arr[i]]>0){
        cout << m[arr[i]]<<" ";
        m[arr[i]]--;
      }else{
        cout <<0<<" ";
      }
    }
    cout <<endl;
  }

}
