
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
 
const int MOD = 1e9 + 7;
int n, m;
long long ncm[200010];
long long two[200010];
long long dp[200010];
 
long long recur(int x, int y)
{
	long long ret;
 
	if (y == 0) return 1;
 
	ret = recur(x, y / 2);
 
	ret *= ret;
	ret %= MOD;
 
	if (y % 2 == 0) return ret;
	else return (x * ret) % MOD;
}

int main()
{
	int t;
	int i;
	long long ans;
	long long mul;
 
	two[0] = 1;
  // 2의 i승의 수를 미리 계산해놓는다.
	for (i = 1; i <= 200000; i++)
	{
		two[i] = two[i - 1] * 2;
		two[i] %= MOD;
	}
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		ncm[0] = 1; //nC0은 무조건 1
    // nCm 을 미리 구해놓는다. 
		for (i = 1; i <= n; i++)
		{
			ncm[i] = ncm[i - 1];
      // nCm분자 부분 자리수를 곱한다. if(m==1) *n,  if(m==2) *(n-1), ... if(m==n) *1.
			ncm[i] *= n - i + 1;
			ncm[i] %= MOD;
      // nCm 분모 부분. 나머지 연산의 곱셈의 역원 (페르마 소정리)
			ncm[i] *= recur(i, MOD - 2);
			ncm[i] %= MOD;
		}
		mul = 0;
    // 1이 짝수개이면 무조건 만족 (xor이 0이 되기 때문)
		for (i = 0; i <= n; i += 2)
		{
			mul += ncm[i];
			mul %= MOD;
		}
    // n이 홀수 일 경우, 모든 수가 1이면 만족하는 케이스 추가 (AND 쪽도 1, XOR  쪽도 1 )  
		mul += n % 2;
    // n이 짝수 일 경우에는 모두 1인 경우를 뺀다 (뒤에서 dp배열을 만들 때는 모든 수가 1인 경우는 따로 계산하기 때문)
		mul -= !(n % 2);
		ans = 1;
    // 모든 자리수에 대해서 앞에서 구한 mul(nC0+nC2+nC4+ .. nCn-2)의 경우의 수가 나오기 때문에
    // mul의 m승을 구해준다. (n이 홀수일 경우에는 이것이 바로 정답) 
		for (i = 0; i < m; i++)
		{
			dp[i] = ans;
			ans *= mul;
			ans %= MOD;
		}
    // 만약 n이 짝수일 경우, And는 1이 되고, Xor는 0이되는 case가 생기기 때문에 기존에 계산한 ans에 아래 경우의 수를 더해주어야 답이된다.
		if (n % 2 == 0)
		{
			for (i = 0; i < m; i++)
			{
        // And==1 이면서 Xor는 0인 위치 앞쪽(and > xor가 되는 위치) 앞에서 구했던 DP값을 이용, 1 뒤쪽은 2^((m-i-1)*n)의 경우의 수
				ans += (dp[i] * recur(two[m - i - 1], n)) % MOD;
				ans %= MOD;
			}
		}
		cout << ans << '\n';
	}
}