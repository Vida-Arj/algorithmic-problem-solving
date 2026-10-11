#include<bits/stdc++.h>
using namespace std;
ifstream in("0096_sudoku.txt");
int a[9][9];
int sum;
string t, s;

bool ok(int a[9][9], int r, int c, int n){
	for(int i = 0; i <= 8; i++)
		if(a[r][i] == n)
			return false;

	for(int i = 0; i <= 8; i++)
		if(a[i][c] == n)
			return false;

	int x = r - (r % 3);
	int y = c - (c % 3);
	for (int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(a[i + x][j + y] == n)
				return false;

	return true;
}

bool ans(int a[9][9], int r, int c){
	if(r == 8 && c == 9)
		return true;
	if(c == 9){
		r++;
		c = 0;
	}
	if(a[r][c] > 0)
		return ans(a, r, c+1);

	for(int i = 1; i <= 9; i++){
		if(ok(a, r, c, i)){
			a[r][c] = i;
			if(ans(a, r, c+1))
				return true;
		}
		a[r][c] = 0;
	}

	return false;
}

int main(){
    while(in >> t >> t){
        for(int i = 0; i < 9; i++){
            in >> s;
            for(int j = 0; j < 9; j++)
                a[i][j] = s[j] - 48;
        }
        if(ans(a, 0, 0))
            sum += a[0][0] * 100 + a[0][1] * 10 + a[0][2];
    }
    cout << sum;
}
