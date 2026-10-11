#include <iostream>
#include <string>
using namespace std;

string s = "0.";
long long ans;

int main(){
    for(int i = 1; s.size() <= 1000001; i++){
        s += to_string(i);
    }
    ans = (s[2] - 48) * (s[11] - 48) * (s[101] - 48) * (s[1001] - 48) * (s[10001] - 48) * (s[100001] - 48) * (s[1000001] - 48);
    cout << ans;
}
