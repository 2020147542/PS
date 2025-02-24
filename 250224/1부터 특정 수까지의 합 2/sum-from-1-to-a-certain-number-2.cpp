#include <iostream>

using namespace std;

int N;

int sum(int n){
    if(n == 1) return 1;

    return n + sum(n-1);
}

int main() {
    cin >> N;

    // Write your code here!
    cout << sum(N) << "\n";

    return 0;
}