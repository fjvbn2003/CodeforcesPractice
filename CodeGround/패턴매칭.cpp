#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){
  fio;
  int test_case;
  cin >> test_case;
  for(int test = 1; test<=test_case; test++){
    ll ans = 0;
    ll N,K;
    cin>> N>>K;
    string s,tmp;
    cin>>s;
    vector<string> patterns;
    for(int i=0; i<K; i++){
      cin>> tmp;
      patterns.push_back(tmp);
    }
    for(auto k : patterns){
      for(int start=0; start<N-k.size()+1; start++){
        vector<bool> mask(k.size(),false);
        for(int i=0; i<k.size(); i++){
          if(mask[i] == true) continue;
          char tok = k[i];
          char tt = s[start+i];
          int cnt = 0;
          bool match = true;
          for(int j=start+i; j<start+k.size(); j++){
            if(k[j-start]==tok){
              if(s[j] == tt)
                cnt++;
              else{
                match = false;
                break;
              }
            }
            if(k[j-start]!=tok && s[j] ==tt){
              match = false;
              break;
            }
          }
          if(match){
            for(int j=start+i; j<start+k.size(); j++){
              if(k[j-start]==tok && s[j]==tt ){
                mask[j-start] = true;
              }
            }
          }
        }
        bool matching = true;
        for(int i=0; i<k.size(); i++){
          if(mask[i] == false){
            matching = false;
            break;
          }
        }
        
        if(matching){
          cout <<"start: "<<start<<endl;
          ans++;
        }
      }
        
    }
    cout << "Case #" << test << "\n";
    cout <<ans<<"\n";
  }
  
}