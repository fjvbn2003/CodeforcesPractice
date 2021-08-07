#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll N, K;
ll T;
ll get_score(ll k, ll y, ll x, vector<vector<ll> > & arr){
  if(y<0 || x<0|| y>=N+2*T ||x>=N+2*T) return 0;
  ll ret =  0ll;
  // 상단
  //cout <<y<<", "<<x<<endl;
  for(ll t = k; t>0; t--){
    if(y+(k-t)>=N+2*T) break;
    //좌측
    for(ll i=1; i<=t-1; i++){
      //cout<<"left: "<<y+(k-t)<<" "<<x-i<<" "<<(t-i)<<endl;
      if(y+(k-t)<N+2*T && x-i>=0){
        ret += arr[y+(k-t)][x-i]*(t-i);
      }else{
        break;
      }
    }
    //가운데
    ret += t*arr[y+(k-t)][x];
    //cout<<"middle: "<<y+(k-t)<<" "<<x<<" "<<(t)<<endl;
    //우측
    for(ll i=1; i<=t-1; i++){
      //cout<<"right: "<<y+(k-t)<<" "<<x+i<<" "<<(t-i)<<endl;
      if(y+(k-t) <N+2*T && x+i<N+2*T){
        ret += arr[y+(k-t)][x+i]*(t-i);
      }else{
        break;
      }
    }
  }
  //cout<<"bleow"<<endl;
  //하단
  for(ll t = k-1; t>0; t--){
    if(y-(k-t)<0) break;
    for(ll i=1; i<=t-1; i++){
      if(y-(k-t)>=0 && x-i>=0){
        //cout<<"left: "<<y-(k-t)<<" "<<x-i<<" "<<(t-i)<<endl;
        ret += arr[y-(k-t)][x-i]*(t-i);
      }else{
        break;
      }
    }
    ret += t*arr[y-(k-t)][x];
    //cout<<"middle: "<<y-(k-t)<<" "<<x<<" "<<(t)<<endl;
    for(ll i=1; i<=t-1; i++){
      if(y-(k-t)>=0 && x+i<N+2*T){
        //cout<<"right: "<<y-(k-t)<<" "<<x+i<<" "<<(t-i)<<endl;
        ret += arr[y-(k-t)][x+i]*(t-i);
      }else{
        break;
      }
    }
  }
  return ret;  
}
int main(){
  fio;
  ll test_case;
  cin >> test_case;
  for(ll test = 1; test<=test_case; test++){
    cin>>N>>K;
    if(K%2==0){
      T = K+1;
    }else{
      T = K+1;
    }
    vector<vector<ll> > arr(N+2*T ,vector<ll>(N+2*T,0));
    
    for(ll i=0; i<N; i++){
      for(ll j=0; j<N; j++){
        cin>>arr[i+T][j+T];
      }
    }
    // for(ll i=0; i<arr.size(); i++){
    //   for(ll j=0; j<arr[i].size(); j++){
    //     cout<<arr[i][j]<<" ";
    //   }
    //   cout <<endl;
    // }



    ll ans = 0ll;
    
    for(ll i=0; i<arr.size(); i++){
      for(ll j=0; j<arr[i].size();  j++){
      // cout << i<<" "<<j<<endl;
      // cout <<"score: "<< get_score(K,i,j, arr)<<endl;
      ans = max(ans,get_score(K,i,j, arr));
      }
    }
    


    cout << "Case #" << test << "\n";
    cout <<ans<<"\n";

  }
  return 0;
}