#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3 + 10;
double dp[MAXN][MAXN];
int N, M, k, r, c;
bool d[MAXN][MAXN];

int32_t main(){
	cin >> N >> M >> k;
	for(int i = 1; i <= k; i++){
		cin >> r >> c;
		d[r][c] = true;
	}

	for(int i = 1; i <= N; i++)
		dp[i][0] = i*100;

	for(int i = 1; i <= M; i++)
		dp[0][i] = i*100;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j<= M; j++){
			dp[i][j] = min(dp[i-1][j] + 100, dp[i][j-1] + 100);
            if(d[i][j])
            	dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 100*sqrt(2));
		}

	cout << round(dp[N][M]) << endl;
}
