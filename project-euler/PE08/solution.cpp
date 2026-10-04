#include <iostream>
using namespace std;

string s;
long long Max, temp;
int main(){
    cin >> s;
    for(int i = 0; i+12 < s.size(); i++){
        temp = 1;
        for(int j = i; j < i+13; j++)
            temp *= ((int)s[j] - 48);
        if (temp > Max)
            Max = temp;
        }
    cout << Max;
}
