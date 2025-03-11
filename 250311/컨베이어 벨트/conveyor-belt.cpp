#include <iostream>
#include <vector>
using namespace std;

int n, t; 
vector<int> arr;

int main() {
    // Please write your code here.
    cin >> n >> t;
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }

    for(int i = 0; i < t; i++){
        int temp = arr[2*n-1];
        for(int j = 2*n-1; j >= 0; j--){
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }

   
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            cout << arr[j * n + i] << " ";
        }
        cout << "\n";
    }

    return 0;
}