#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x1[100], x2[100];
int line[111];
int aa, bb;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];

        if(i == 0){
            aa = x1[i];
            bb = x2[i];
        }else{
            if(bb < x1[i] || x2[i] < aa){
                cout << "No";
                return 0;
            } else{
                aa = max(aa, x1[i]);
                bb = min(bb, x2[i]);
            }
        }
    }

    cout << "Yes";
    return 0;
}