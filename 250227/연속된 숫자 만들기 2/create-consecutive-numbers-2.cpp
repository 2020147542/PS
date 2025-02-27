#include <iostream>
#include <algorithm>
using namespace std;

int a[3];

int main(){
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    if(a[0] + 1 == a[1] && a[1] + 1 == a[2]) {
        cout << 0;
        return 0;
    }

    if(a[1] - a[0] == 2 || a[2] - a[1] == 2){
        cout << 1;
        return 0;
    }

    cout << 2;
    return 0;
}