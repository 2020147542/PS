#include <iostream>
using namespace std;

int n, cur, x, ans;
int line[2222];
char dir;

int main(){
    cin >> n;

    cur = 1010;
    for(int k = 0; k < n; k++){
        cin >> x >> dir;

        if(dir == 'L'){
            for(int i = cur - 1; i >= cur - x; i--){
                line[i]++;
            }
            cur = cur - x;
        } else{
            for(int i = cur; i < cur + x; i++){
                line[i]++;
            }
            cur = cur + x;
        }
    }

    for(int i = 0; i < 2222; i++){
        ans = line[i] >= 2 ? ans + 1 : ans;
    }

    cout << ans;

    return 0;
}