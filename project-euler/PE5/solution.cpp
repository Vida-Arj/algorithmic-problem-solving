#include <iostream>
using namespace std;

bool isDiv(int x) {
    for (int i = 11; i <= 20; i++)
        if (x % i != 0)
            return false;
    return true;
}

int main() {
    int answer = 2520;
    while (!isDiv(answer))
        answer++;
    cout << answer;
}
