#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];
int line[111];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        for(int j = x1[i]; j <= x2[i]; j++){
            line[j]++;
        }
    }

    // Please write your code here.
    for(int i = 0; i < 111; i++){
        if(line[i] == n) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}