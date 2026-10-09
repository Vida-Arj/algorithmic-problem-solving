#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7, N = 5e4 + 10;
int dpa[N], dpb[N], n, a, b;
int32_t main(){
	cin >> n >> a >> b;

	dpa[0] = 1;
	dpa[1] = 1;
	dpb[0] = 1;
	dpb[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = i - 1; j >= 0 && i-j <= a; j--)
			dpa[i] = (dpa[i] + dpb[j]) % M;
		for(int j = i - 1; j >= 0 && i-j <= b; j--)
			dpb[i] = (dpb[i] + dpa[j]) % M;
	}

	cout << (dpa[n] + dpb[n]) % M << endl;
}
