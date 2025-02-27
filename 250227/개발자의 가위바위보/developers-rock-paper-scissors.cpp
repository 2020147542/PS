#include <iostream>
using namespace std;

int n, res;
int a[111];
int b[111];
int ans[4];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) continue;
    
        if(ans[a[i]] == 0 || ans[a[i]] == b[i]){
            res++;   
            ans[a[i]] = b[i];
        }
    }

    cout << res;
    return 0;
}