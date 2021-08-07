#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<pair<int, int> > make_8k_points(int k, int x, int y){
  vector<pair<int, int> > pts;
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
void move_points(vector<pair<int, int> >& pts, int x, int y){
  for(int i=0; i<8; i++){
    pts[i].first += x;
    pts[i].second += y;
  }
  return ;
}
ll dist(vector<pair<int, int> >& a,vector<pair<int, int> >& b ){
  ll d = 1e18;
  // 8 permutation
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  do{
    ll t=0;
    for(int i=0; i<8; i++){
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
int main(){
  fio;
  int test_case,a,b;
  cin>>test_case;
  for(int test=1; test<=test_case; test++){
    int K;
    cin>>K;
    vector<pair<int, int> > pts(8, pair<int, int>());
    for(int i=0; i<8; i++){
      cin>>a>>b;
      pts[i] = {a,b};
    }
    ll ans = 1e18;
    // for(int i=-K; i<18-K; i++){
    //   for(int j=-K; j<18-K; j++){
    //     auto t_pts = make_8k_points(K, i, j);
    //     ll tmp = dist(pts, t_pts, ans);
    //     if(tmp<ans){
    //       ans = tmp;
    //       cout <<i<<" "<<j<<" : " <<tmp<<endl;
    //     }
    //   }
    // }


    //삼분 탐색
    int R = 20;
    int left = -(R*R);
    int right = R*R;
    cout <<"left: "<<left<<endl;
    for(int iter=0; iter<30; iter++){
      int m1 = (2*left+right)/3;
      int m2 = (left+2*right)/3;
      int m1_x = m1/R;
      int m1_y = m1%R;
      int m2_x = m2/R;
      int m2_y = m2%R;
      cout << left<<" "<<right <<" "<<m1_x<<" "<<m1_y<<" "<<m2_x<<" "<<m2_y<<endl;
      auto m1_pts = make_8k_points(K, m1_x, m1_y);
      auto m2_pts = make_8k_points(K, m2_x, m2_y);
      ll d_m1 = dist(pts, m1_pts);
      ll d_m2 = dist(pts, m2_pts);
      cout <<"dist: "<< d_m1<<" "<<d_m2<<endl;
      if(d_m1<d_m2){
        right = m2;
      }else{
        left = m1;
      }
    }
    int m_x = ((left+right)/2)/R;
    int m_y = ((left+right)/2)%R;
    //cout<<"m_x: "<<m_x<<" m_y: " <<m_y<<endl;
    auto m_pts = make_8k_points(K, m_x, m_y);
    ans = dist(pts, m_pts);
    cout << "Case #"<<test<<'\n';
    cout << ans<<'\n';
  }
  return 0;
}
