#include <iostream>

using namespace std;

int N;

int fibo(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;

    return fibo(n-1) + fibo(n-2);
}

int main() {
    cin >> N;

    // Write your code here!
    cout << fibo(N) << endl;

    return 0;
}