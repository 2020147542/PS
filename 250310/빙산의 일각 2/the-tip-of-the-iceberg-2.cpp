#include <iostream>
#include <climits>
using namespace std;

int n;
int h[111];
int max_height = INT_MIN;
int max_val = INT_MIN;

int main() {

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        max_height = max(max_height, h[i]);
    }
    
    for(int i = 0; i <= max_height; i++){
        int cnt = 0;

        for(int j = 1; j <= n; j++){
            if(h[j-1] - i <= 0 && h[j] - i > 0) cnt++;
        }

        max_val = max(max_val, cnt);
    }

    cout << max_val;

    return 0;
}