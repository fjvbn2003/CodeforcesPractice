//
// Created by Yongju KIM on 2021/11/06.
//

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
using namespace std;

int num[105][50005] = { 0, };

struct Q {
    string s; int a; int b;
};

void solved() {
    int N; cin >> N;
    set <string> s;
    vector <string> v;
    vector <pair<int, int>> tmp;
    rep(i, N) {
        string a, b;
        int c, d;
        cin >> a >> b >> c >> d;

        if (s.find(a) == s.end()) {
            s.insert(a);
            v.push_back(b);
            tmp.push_back({ c, d });
        }
    }
    map <string, int> mp;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (mp.find(v[i]) == mp.end()) {
            mp[v[i]] = cnt++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int k = tmp[i].first; k < tmp[i].second; k++) {
            num[mp[v[i]]][k]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 50005; j++) {
            ans = max(ans, num[i][j]);
        }
    }

    vector <Q> ret;
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 50005; j++) {
            if (ans == num[i][j]) {
                int k = j;
                while (j < 50005 && num[i][j] == ans) j++;

                string t;
                for (auto iter = mp.begin(); iter != mp.end(); iter++) {
                    if (iter->second == i) t = iter->first;
                }
                ret.push_back({ t, k, j });
            }
        }
    }
    string ansa; ansa = ret[0].s;
    int ansb = ret[0].a, ansc = ret[0].b;

    for (int i = 1; i < ret.size(); i++) {
        if (ansa > ret[i].s) {
            ansa = ret[i].s;
            ansb = ret[i].a;
            ansc = ret[i].b;
        }
    }

    cout << ansa << " " << ansb << " " << ansc;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    solved();
    return 0;
}