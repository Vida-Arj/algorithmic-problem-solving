#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 50;
int dp[M], N;
int32_t main(){
	cin >> N;
	dp[1] = 2;
	dp[2] = 2;
	for(int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[N];
}
