#include <iostream>
using namespace std;

int a[21][21], Max;

int main () {
    for (int i = 1; i < 21; i++)
        for (int j = 1; j < 21; j++)
            cin >> a[i][j];
    Max = 0;
    for (int i = 1; i+3 < 21; i++)
        for(int j = 1; j < 21; j++)
            if (a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j] > Max)
                Max = a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j];

    for (int i = 1; i < 21; i++)
        for(int j = 1; j+3 < 21; j++)
            if (a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3] > Max)
                Max = a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3];

    for (int i = 1; i+3 < 21; i++)
        for(int j = 1; j+3 < 21; j++)
            if (a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3] > Max)
                Max = a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3];

    for (int i = 4; i < 21; i++)
        for(int j = 1; j+3 < 21; j++)
            if (a[i][j] * a[i-1][j+1] * a[i-2][j+2] * a[i-3][j+3] > Max)
                Max = a[i][j] * a[i-1][j+1] * a[i-2][j+2] * a[i-3][j+3];

    cout << Max;
}
