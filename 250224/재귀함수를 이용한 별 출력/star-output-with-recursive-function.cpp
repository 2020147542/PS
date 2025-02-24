#include <iostream>

using namespace std;

int n;

void star(int size){
    if(size == 0) return;

    star(size - 1);
    for(int i = 0; i < size; i++){
        cout << "*";
    }
    cout << "\n";
}

int main() {
    cin >> n;

    // Write your code here!
    star(n);

    return 0;
}