#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int x1[100], x2[100];
int line[201];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    // Write your code here!
    for (int i = 0; i < n; i++) {
        for(int j = x1[i]+100; j < x2[i]+100; j++){
            ans = max(ans, ++line[j]);
        }
    }

    cout << ans << "\n";

    return 0;
}