#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100];

int find_max(int idx){
    if(idx == 0) return arr[idx];

    return max(arr[idx], find_max(idx - 1));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Write your code here!
    cout << find_max(n) << endl;

    return 0;
}