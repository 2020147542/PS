#include <iostream>

using namespace std;

int N;

int cnt(int n){
    if(n == 1) return 0;

    if(n % 2){
        return cnt(n / 3) + 1;
    }else{
        return cnt(n / 2) + 1;
    }
}

int main() {
    cin >> N;

    // Write your code here!
    cout << cnt(N) << endl;

    return 0;
}