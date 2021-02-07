#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<pair<ll, int> > arr;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,d,m,t, abil;
    int k;
    cin>>n>>k>>d;
    for(int i=0; i<n; i++){
        cin>>m>>abil;
        int a = 0;
        for(ll j=0; j<m; j++){
            cin>>t;
            t--;
            a |= (1<<t);
        }
        //cout <<a<<endl;
        arr.push_back({abil,a});
    }

    sort(arr.begin(), arr.end());
int l = 0;
int r = 0;
ll ans = 0;
 int uni = 0;
 int sub = 0;
 int cnt_uni,cnt_sub;

    while(r<=n-1 && l<=r){
        while(arr[r].first - arr[l].first < d){
            r++;
            if(r == n-1) break;
        }
        
        //cout <<"r: "<<r<<endl;
        uni = 0;
        cnt_uni=0;
        cnt_sub = 0;
        sub = (1<<k)-1;
        for(ll i=l; i<=r; i++){
            uni |= arr[i].second;
            sub &= arr[i].second;
        }
        cnt_uni = __builtin_popcount(uni);
        cnt_sub = __builtin_popcount(sub);
        ans = max(ans, (ll)(cnt_uni-cnt_sub)*(r-l+1));
        l++;
    }
    cout <<ans<<endl;
    return 0;

}