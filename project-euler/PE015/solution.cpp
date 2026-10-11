#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 30, N = 20;
int dp[M][M];

int32_t main(){
    dp[0][0] = 1;
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++){
            if (i > 0)
                dp[i][j] += dp[i-1][j];
            if (j > 0)
                dp[i][j] += dp[i][j-1];
        }

    cout << dp[N][N];
}
