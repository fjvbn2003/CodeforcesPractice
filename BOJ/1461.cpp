#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
     int n,  m;
     vector<int> plus;
     vector<int> minus;
    int t;
     cin>>n>>m;
     for(int i=0; i<n; i++){
         cin>>t;
         if(t>0){
             plus.push_back(t);
         }else{
             minus.push_back(-t);
         }
     }
     int ans = 0;
     sort(plus.begin(), plus.end());
     sort(minus.begin(), minus.end());
     int p_idx = plus.size()-1;
     int m_idx = minus.size()-1;
     if(p_idx==-1) plus.push_back(0);
     if(m_idx==-1) minus.push_back(0);
     if(plus.back() > minus.back()){
         p_idx -=m;
         ans += plus.back();
     }else{
         m_idx -=m;
         ans += minus.back();
     }
     while(p_idx>=0){
         ans += plus[p_idx]*2;
         p_idx -= m;
     }
     while(m_idx >=0){
         ans += minus[m_idx]*2;
         m_idx -= m;
     }
     cout << ans<<endl;
     return 0;
}