#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ret;
    vector<int> bit;

    for (auto& i : orders) {
        int b = 0;
        for (char ch : i) b |= 1 << ch - 65;
        bit.push_back(b);
    }

    bool vis[11]{};
    for (int i : course) vis[i] = 1;

    vector<int> cdd[11];
    int mx[11]{};
    for (int i = 1; i < 1 << 26; ++i) {
        int bitcnt = __builtin_popcount(i);
        if (!vis[bitcnt]) continue;

        int cnt = 0;
        for (int j : bit) cnt += (j & i) == i;
        if (cnt > 1 && cnt > mx[bitcnt]) {
            mx[bitcnt] = cnt;
            cdd[bitcnt].clear();
            cdd[bitcnt].push_back(i);
        }
        else if (cnt > 1 && cnt == mx[bitcnt]) {
            cdd[bitcnt].push_back(i);
        }
    }

    for (int i : course) {
        for (int j : cdd[i]) {
            string t;
            for (int k = 0; k < 26; ++k) if (j & 1 << k) t += char(k + 65);
            ret.push_back(t);
        }
    }

    sort(ret.begin(), ret.end());

    return ret;
}