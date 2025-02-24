#include <iostream>

using namespace std;

int n;

void print(int n){
    if(n == 0) return;

    for(int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << "\n";
    print(n - 1);
    for(int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << "\n";
}

int main() {
    cin >> n;

    // Write your code here!
    print(n);

    return 0;
}