#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20], n, k;
int32_t main(){
	cin >> n >> k;
	dp[0] = 1;
	dp[1] = k-1;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] * (k-1) + dp[i-2] * (k-1);
	}

	cout << dp[n] << endl;
}
