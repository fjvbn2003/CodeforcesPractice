#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, K, D;
pii A[101010];
int ans;

int cnt[30];

int main() {
	scanf("%d%d%d", &N, &K, &D);
	for(int i = 1; i <= N; i++) {
		int m; scanf("%d%d", &m, &A[i].first);
		for(int j = 0; j < m; j++) {
			int x; scanf("%d", &x);
			A[i].second |= 1 << x - 1;
		}
	}

	sort(A + 1, A + N + 1);
	int l = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 30; j++) cnt[j] += !!(A[i].second & 1 << j);
		while(A[i].first - A[l].first > D) {
			for(int j = 0; j < 30; j++) cnt[j] -= !!(A[l].second & 1 << j);
			l++;
		}
		int t = 0;
		for(int j = 0; j < 30; j++) t += (cnt[j] > 0 && cnt[j] < i - l + 1);
		ans = max(ans, t * (i - l + 1));
	}
	printf("%d\n", ans);
	return 0;
}