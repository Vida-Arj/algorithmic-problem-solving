#include<bits/stdc++.h>
using namespace std;
set<int> s;
int sum;
vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void dgt(int &x, int &y, int &n){
    x = 0;
    for(int i = 1; i <= y; i++){
        x *= 10;
        x += v[n++];
    }
}

int main(){
    do{
        for(int i = 1; i < 9; i++){
            for(int j = 1; j < 9; j++){
                int k = 9 - i - j;
                if(!(k >= i && k >= j))
                    break;
                int a, b, c, d = 0;
                dgt(a, i, d);
                dgt(b, j, d);
                dgt(c, k, d);
                if(a*b == c)
                    s.insert(c);
            }
        }
    }while(next_permutation(v.begin(), v.end()));
    for(auto x : s)
        sum += x;
    cout << sum;
}
