#include <iostream>
using namespace std;

int n, q;
const int max_val = 1111111;
int arr[max_val];
int cnt[max_val];

int main() {
    // Please write your code here.
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int idx;
        cin >> idx;
        arr[idx+1] = 1;
    }

    for(int i = 1; i < max_val; i++){
        cnt[i] = cnt[i-1] + arr[i];
    }
    
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << cnt[b+1] - cnt[a+1] + arr[a+1] << "\n";
    }

    return 0;
}