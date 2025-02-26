#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    // Please write your code here.
    for (int k = 0; k < n; k++){
        int aa = -1, bb = 100000;

        for (int i = 0; i < n; i++) {
            if(i == k) continue;
            aa = max(aa, x1[i]);
            bb = min(bb, x2[i]);
        }

        if(aa <= bb){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}