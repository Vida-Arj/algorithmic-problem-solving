#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 60, N = 50;
int dp[M];

int32_t main(){
	dp[0] = 1;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= 4; j++)
			if(j <= i)
                dp[i] += dp[i - j];
	cout << dp[N];
}
