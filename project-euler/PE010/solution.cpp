#include<iostream>
using namespace std;

const int M = 2e6;
bool p[M];
long long sum;

int main(){
    for(long long i = 2; i < M; i++)
        p[i] = true;
    for(long long i = 2; i < M; i++)
        if(p[i]){
            for(long long j = i; i*j < M; j++)
                p[i*j] = false;
            sum += i;
        }
    cout << sum;
}
