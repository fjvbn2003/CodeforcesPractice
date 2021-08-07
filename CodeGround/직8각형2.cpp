#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll dist1d(vector<ll> a, vector<ll> b){
  ll d = 1e18;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  do{
    ll t = 0;
    for(ll i=0; i<8; i++){
      t += abs(a[i] - b[i]);
      t += abs(a[i] - b[i]);    
      
    }
    if(t<d){
      d = t;
    }
  }while(next_permutation(b.begin(), b.end()));
  return d;
}
ll dist2d(vector<pair<ll, ll> >& a,vector<pair<ll, ll> >& b ){
  ll d = 1e18;
  // 8 permutation
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  do{
    ll t=0;
    for(ll i=0; i<8; i++){
      t += abs(a[i].first - b[i].first);
      t += abs(a[i].second - b[i].second);
      if(t>d) break;
    }
    if(t<d){
      d = t;
    }
  }while(next_permutation(b.begin(), b.end()));
  return d;
}
vector<pair<ll, ll> > make_8k_pts(ll k, ll x, ll y){
  vector<pair<ll, ll> > pts;
  pts.push_back({x, y+k});
  pts.push_back({x, y+2*k});
  pts.push_back({x+k, y});
  pts.push_back({x+2*k, y});
  pts.push_back({x+3*k, y+k});
  pts.push_back({x+3*k, y+2*k});
  pts.push_back({x+k, y+3*k});
  pts.push_back({x+2*k, y+3*k});
  return pts;
}
vector<ll> make_1d_pts(ll k, ll x){
  vector<ll> pts;
  for(ll i=0; i<4; i++){
    pts.push_back(x+i*k);
    pts.push_back(x+i*k);
  }
  return pts;
}
int main(){
  fio;
  ll test_case,a,b;
  cin>>test_case;
  for(ll test=1; test<=test_case; test++){
    ll K;
    cin>>K;
    vector<pair<ll, ll> > pts(8, pair<ll, ll>());
    vector<ll> pts_x(8,0);
    vector<ll> pts_y(8,0);
    for(ll i=0; i<8; i++){
      cin>>a>>b;
      pts[i] = {a,b};
      pts_x[i] = a;
      pts_y[i] = b;
    }
    ll R = 12345678912345ll;
    ll left = -R;
    ll right = R;
    for(ll iter=0; iter<100; iter++){
      ll m1 = (2*left+right)/3;
      ll m2 = (left+2*right)/3;
      auto m1_pts = make_1d_pts(K,m1);
      auto m2_pts = make_1d_pts(K,m2);
      ll d_m1 = dist1d(pts_x, m1_pts);
      ll d_m2 = dist1d(pts_x, m2_pts);
      //cout << m1<<" "<<m2<<endl;
      //cout <<"dist: "<< d_m1<<" "<<d_m2<<endl;
      if(d_m1<d_m2){
        right = m2-1;
      }else{
        left = m1;
      }
    }
    ll ans_x = (left+right)/2;
    for(int i=-5; i<5; i++){
      if(dist1d(pts_x, make_1d_pts(K, ans_x+i))<dist1d(pts_x, make_1d_pts(K, ans_x))){
          ans_x = ans_x+i;
      }
    }

    R = 12345678912345ll;
    left = -R;
    right = R;
    for(ll iter=0; iter<100; iter++){
      ll m1 = (2*left+right)/3;
      ll m2 = (left+2*right)/3;
      auto m1_pts = make_1d_pts(K,m1);
      auto m2_pts = make_1d_pts(K, m2);
      ll d_m1 = dist1d(pts_y, m1_pts);
      ll d_m2 = dist1d(pts_y, m2_pts);
      //cout << m1<<" "<<m2<<endl;
      //cout <<"dist: "<< d_m1<<" "<<d_m2<<endl;
      if(d_m1<d_m2){
        right = m2-1;
      }else{
        left = m1;
      }
    }
    ll ans_y = (left+right)/2;
    for(int i=-5; i<5; i++){
      if(dist1d(pts_y, make_1d_pts(K, ans_y+i))<dist1d(pts_y, make_1d_pts(K, ans_y))){
        ans_y = ans_y+i;
      }
    }

    
    //cout <<ans_x<<" "<<ans_y<<endl;
    auto t_pts = make_8k_pts(K, ans_x, ans_y);
    cout << "Case #"<<test<<'\n';
    cout << dist2d(pts, t_pts)<<'\n';
  }
  return 0;
}