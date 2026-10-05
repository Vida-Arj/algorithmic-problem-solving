#include<bits/stdc++.h>
using namespace std;
set<vector<int> > s;
vector<int> v;

vector<int> mult(vector<int> m, int n){
    m.resize(201);
    int carry = 0;
    for(int i = 0; i < m.size(); i++){
        m[i] *= n;
        m[i] += carry;
        carry = m[i] / 10;
        m[i] %= 10;
    }
    return m;
}

int main(){
    for(int a = 2; a <= 100; a++){
        v = {a};
        for(int b = 2; b <= 100; b++){
            v = mult(v, a);
            s.insert(v);
        }
    }
    cout << s.size();
}
