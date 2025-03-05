#include <iostream>
using namespace std;

int n, cnt;
string a;

int main() {
    // Please write your code here.
    cin >> n >> a;

    // 모든 경우에
    // 모든 문자열을 돌면서 
    for(int i = 0; i < n; i++){
        // 할거하자
        // cow 순서로 나오는 수를 세자
        if(a[i] == 'C'){
            for(int j = i+1; j < n; j++){
                if(a[j] == 'O'){
                    for(int k = j+1; k < n; k++){
                        if(a[k] == 'W') cnt++;
                    }
                }
            }
        }
    }
    
    cout << cnt;
    return 0;
}