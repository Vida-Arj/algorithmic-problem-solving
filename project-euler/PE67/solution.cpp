#include<bits/stdc++.h>
using namespace std;
ifstream in("0067_triangle.txt");
#define int long long
const int M = 110, N = 100;
int a[M][M], dp[M][M];

int32_t main()
{
	for(int i = 1; i <= N; i++)
		for(int j = 1;j <= i; j++)
			in >> a[i][j];
	for(int i = N; i >= 1; i--)
		for(int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
	cout << dp[1][1];
}
