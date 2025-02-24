#include <iostream>

using namespace std;

int N;

void print(int n){
    if(n == 0) return;
    
    cout << "HelloWorld\n";
    print(n - 1);
}

int main() {
    cin >> N;

    // Write your code here!
    print(N);

    return 0;
}