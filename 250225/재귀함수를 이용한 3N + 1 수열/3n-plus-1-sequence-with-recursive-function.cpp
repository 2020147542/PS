#include <iostream>

using namespace std;

int n;

int count(int n){
    if(n == 1){
        return 0;
    }
    
    if(n % 2){
        return count(n * 3 + 1) + 1;
    } else{
        return count(n / 2) + 1;
    }
}

int main() {
    cin >> n;

    // Write your code here!
    cout << count(n) << endl;

    return 0;
}