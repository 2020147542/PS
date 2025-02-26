#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int x1, x2;
int arr[201];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x1 >> x2;

        for(int j = x1 + 100; j < x2 + 100; j++){
            arr[j]++;
        }
    }

    for(int i = 0; i < 201; i++){
        ans = max(ans, arr[i]);
    }

    cout << ans;

    return 0;
}