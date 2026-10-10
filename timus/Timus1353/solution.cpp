#include<bits/stdc++.h>
using namespace std;
#define int long long
int s, dp[15][90], ans;
int VF(int d, int s){
    if(s < 0)
        return 0;
	if(d == 0){
		if(s == 0)
			return 1;
		else
			return 0;
	}
	if(dp[d][s] != -1)
		return dp[d][s];
	else{
		dp[d][s] = 0;
		for(int i = 0; i <= 9; i++){
			dp[d][s] += VF(d-1, s-i);
		}
		return dp[d][s];
	}
}
int32_t main(){
	cin >> s;
	for(int i = 0; i <= 9; i++)
		for(int j = 0; j <= 81; j++)
			dp[i][j] = -1;
	ans = VF(9, s);
	if(s == 1)
		ans++;
	cout << ans << endl;
}
