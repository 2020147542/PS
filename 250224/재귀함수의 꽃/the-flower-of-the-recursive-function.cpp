#include <iostream>

using namespace std;

int N;

void print(int n){
    if(n == 0) return;

    cout << n << " ";
    print(n-1);
    cout << n << " ";
}

int main() {
    cin >> N;

    // Write your code here!
    print(N);

    return 0;
}