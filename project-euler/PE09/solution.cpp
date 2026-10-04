#include <iostream>
using namespace std;

void swp (int &a, int &b){
    int t;
    if (a > b){
        t = a;
        a = b;
        b = t;
    }
}

bool pytha(int a ,int b, int c){
    if (a > b)
        swp(a, b);
    if (a > c)
        swp(a, c);
    if (b > c)
        swp(b, c);
    if (a*a + b*b == c*c && a + b + c == 1000)
        return true;
    return false;
}

int main(){
    for(int i = 1; i <= 998; i++)
        for(int j = 1; j <= 998; j++)
            for(int k = 1; k <= 998; k++)
                if (pytha(i, j, k)){
                    cout << i*j*k;
                    exit(0);
                    }
}
