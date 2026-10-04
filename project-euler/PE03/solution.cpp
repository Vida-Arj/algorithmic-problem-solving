#include<iostream>
using namespace std;

long long prifac(long long x){
    long long maxFactor = 1;
    for(long long i = 2; i*i <= x; i++)
        while(x % i == 0){
            x /= i;
            if (x > 1)
                maxFactor = x;
        }
    if (x > 1)
        return x;
    else
        return maxFactor;
}

int main()
{
    cout << prifac(600851475143);
}
