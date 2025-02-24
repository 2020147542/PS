#include <iostream>

using namespace std;

int N;

int fact(int n){
    if(n <= 2) return n;

    return n * fact(n-1);
}

int main() {
    cin >> N;

    // Write your code here!
    cout << fact(N) << endl;

    return 0;
}