#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x1, x2, ans;
int line[111];

int main(){ 

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x1 >> x2;

        for(int x = x1; x <= x2; x++){
            line[x]++;
        }
    }

    for(int i = 0; i < 111; i++){
        ans = max(ans, line[i]);
    }

    cout << ans;

    return 0;
}