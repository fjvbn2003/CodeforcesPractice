#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"
/*
Author: fjvbn2003
Round: 
problem:
*/
#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    #endif 
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<set<int>> g(n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].insert(y);
			g[y].insert(x);
		}
		vector<int> val(n, 1);
		queue<int> leafs;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == 1) {
				leafs.push(i);
			}
		}
		while (!leafs.empty()) {
			int v = leafs.front();
			leafs.pop();
			int to = *g[v].begin();
			val[to] += val[v];
			val[v] = 0;
			g[v].clear();
			g[to].erase(v);
			if (g[to].size() == 1) {
				leafs.push(to);
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += val[i] * 1ll * (val[i] - 1) / 2;
			ans += val[i] * 1ll * (n - val[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}
