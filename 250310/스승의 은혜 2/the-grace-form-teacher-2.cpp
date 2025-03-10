#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int p[1111];

int main() {
    // Please write your code here.
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    sort(p, p+n);
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(sum + p[i] <= c){
            sum += p[i];
            cnt++;
        } else if(sum + p[i]/2 <= c){
            cnt++;
            break;
        }
    }

    cout << cnt;

    return 0;
}