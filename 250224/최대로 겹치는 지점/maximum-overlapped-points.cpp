#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int x1[100];
int x2[100];
int line[101];

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> x1[i] >> x2[i];

        for(int j = x1[i]; j <= x2[i]; j++){
            ans = max(ans, ++line[j]);
        }
    }

    cout << ans << "\n";

    return 0;
}