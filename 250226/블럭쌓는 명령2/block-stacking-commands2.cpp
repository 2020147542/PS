#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a, b, ans;
int arr[101];

int main(){
    cin >> n >> k;

    for(int i=0; i <k; i++){
        cin >> a >> b;

        for(int j = a; j <= b; j++){
            ans = max(ans, ++arr[j]);
        }
    }

    cout << ans;

    return 0;
}