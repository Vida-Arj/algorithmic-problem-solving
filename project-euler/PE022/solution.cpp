#include<bits/stdc++.h>
using namespace std;
ifstream in("names.txt");
vector<string> v;
string s, p;
int score, sum;

int main(){
    in >> s;
    int k = 1;
    while(k < s.size()){
            p = "";
       while(s[k] >= 'A' && s[k] <= 'Z'){
            p += s[k];
            k++;
       }
       v.push_back(p);
       k += 3;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        sum = 0;
        for(int j = 0; j < v[i].size(); j++){
            sum += v[i][j] - 64;
        }
        score += sum * (i + 1);
    }
    cout << score;
}
