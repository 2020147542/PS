#include <iostream>

using namespace std;

int a, b, c;

int print(int n){
    if(n < 10) return n;

    return print(n / 10) + n % 10;
}

int main() {
    cin >> a >> b >> c;

    // Write your code here!
    cout << print(a * b * c) << endl;

    return 0;
}