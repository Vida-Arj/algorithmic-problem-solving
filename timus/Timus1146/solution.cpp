#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 110;
int n, a[M][M], dp[M][M], ans = -1290000;
int32_t main()
{
	cin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1;j <= n; j++)
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int x = 1;x <= i; x++)
				for(int y = 1; y <= j; y++)
					ans = max(ans, dp[i][j] - dp[x-1][j] - dp[i][y-1] + dp[x-1][y-1]);
	cout << ans << endl;
}
