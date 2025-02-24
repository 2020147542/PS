#include <iostream>

using namespace std;

int N;

int sol(int n){
    if(n < 10) return n * n;

    return sol(n / 10) + (n % 10) * (n % 10);
}

int main() {
    cin >> N;

    // Write your code here!
    cout << sol(N) << endl;

    return 0;
}