#include <iostream>
using namespace std;

int n, t;
int belt[10];

int main() {
    // Please write your code here.
    cin >> n >> t;

    for(int i = 1; i <= 3 * n; i++){
        cin >> belt[i];
    }

    for(int i = 0; i < t; i++){
        int temp = belt[3 * n];
        for(int j = 3 * n; j >= 2; j--){
            belt[j] = belt[j-1];
        }
        belt[1] = temp;
    }

    for(int i = 1; i <= 3 * n; i++){
        cout << belt[i] << " ";
        if(i % n == 0) cout << "\n";
    }

    return 0;
}