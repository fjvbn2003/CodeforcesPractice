#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#define ll long long
#include <bits/stdc++.h>
using namespace std;
bool primes [500000];
vector<ll> prime;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    #endif 
for(int i=2; i<500000; i++){
     primes[i] = true;
}
for(int i=2; i*i < 500000; i++){
    if(primes[i]){
        for(int k=i*i; k<500000; k+=i){
            primes[k] = false;
        }
    }
}
for(int i=1; i<500000; i++){
    if(primes[i]){
        prime.push_back(i);
    }
}
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
   long long n;
		cin >> n;
	
		vector<pair<int, long long>> val;
		for (long long i = 2; i * i <= n; ++i) {
			int cnt = 0;
			while (n % i == 0) {
				++cnt;
				n /= i;
			}
			if (cnt > 0) {
				val.push_back({cnt, i});
			}
		}
		if (n > 1) {
			val.push_back({1, n});
		}
	
		sort(val.rbegin(), val.rend());
		vector<long long> ans(val[0].first, val[0].second);
		for (int i = 1; i < int(val.size()); ++i) {
			for (int j = 0; j < val[i].first; ++j) {
				ans.back() *= val[i].second;
			}
		}
	
		cout << ans.size() << endl;
		for (auto it : ans) cout << it << " ";
		cout << endl;
}


/*
Author: fjvbn2003
Round: #
problem: D.
*/