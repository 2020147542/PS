#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int n, max_val = INT_MIN;
int times[1111];
int a[111];
int b[111];

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < n; i++){
        memset(times, 0, sizeof(times));

        for(int j = 0; j < n; j++){
            if(i == j) continue;
            for(int k = a[j]; k < b[j]; k++){
                times[k] = 1;
            }
        }

        int cnt = 0;
        for(int j = 0; j < 1111; j++){
            if(times[j]) cnt++;
        }

        max_val = max(max_val, cnt);
    }

    cout << max_val;
    return 0;
}