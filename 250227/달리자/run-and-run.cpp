#include <iostream>
using namespace std;

int n, ans;
int a[111];
int b[111];

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    for(int i = 1; i <= n; i++){
        if(b[i] == a[i]) continue;

        if(b[i] - a[i] < 0){
            a[i+1] += (a[i] - b[i]);
            ans += (a[i] - b[i]);
        }
    }

    cout << ans;

    return 0;
}