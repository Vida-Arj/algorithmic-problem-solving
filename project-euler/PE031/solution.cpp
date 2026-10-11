#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[]={0, 1, 2, 5, 10, 20, 50, 100, 200}, n = 8, dp[202][10];

int32_t main(){
	for(int i = 1; i <= 8; i++)
		dp[0][i] = 1;
	for(int i = 1; i <= 200; i++)
		for(int j = 1; j <= 8; j++){
			dp[i][j] = dp[i][j-1];
			if(i - c[j] >= 0)
				dp[i][j] += dp[i-c[j]][j];
		}
	cout<<dp[200][8]<<endl;
}
