#include <iostream>
#include <vector>
using namespace std;

int main(){
  int test_case;
  cin>> test_case;
  int k,n,m;
  int ai,bi;
  while(test_case--){
    cin>> k>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++)
      cin>>a[i];
    for(int i=0; i<m; i++)
      cin>>b[i];
    ai = 0;
    bi = 0;
    bool flag = false;
    vector<int> ans;
    while(1){
      while(ai<n && a[ai] ==0){
        ai++;
        k++;
        ans.push_back(0);
      }
      while(bi<m && b[bi] ==0){
        bi++;
        k++;
        ans.push_back(0);
      }
      if(ai ==n && bi==m){
        break;
      }
      if(ai<n && a[ai] <=k){
        ans.push_back(a[ai]);
        ai++;
      }
      else if(bi<m && b[bi] <=k){
        ans.push_back(b[bi]);
        bi++;
      }
      else{
        flag =true;
        break;
      }
    }
    if(flag){
      cout <<-1<<endl;
    }else{
      for(int i=0; i<ans.size(); i++){
        cout <<ans[i]<<" ";
      }
      cout <<endl;
    }
  }

}