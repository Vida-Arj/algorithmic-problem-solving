#include<bits/stdc++.h>
using namespace std;
int a[12] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, k;

int main(){
    do{
        k++;
        if (k == 1000000){
            for(int i = 1; i <= 10; i++)
                cout << a[i];
            break;
        }
    }while(next_permutation(a+1, a+11));
}
