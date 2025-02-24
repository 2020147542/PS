#include <iostream>

using namespace std;

int N;

int found(int n) {
    if(n == 1 || n == 2) return 2 * n;

    return found(n - 2) * found(n - 1) % 100;
}

int main() {
    cin >> N;

    // Write your code here!
    cout << found(N) << endl;

    return 0;
}