#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 60, N = 50;
int dp[M];

int Fill(int x){
    for(int i = 0; i <= N; i++)
        dp[i] = 0;
	dp[0] = 1;
	for(int i = 1; i <= N; i++){
		dp[i] += dp[i - 1];
		if(i >= x)
			dp[i] += dp[i - x];
	}
	return dp[N] - 1;
}

int32_t main(){

    cout << Fill(2) + Fill(3) + Fill(4);
}
