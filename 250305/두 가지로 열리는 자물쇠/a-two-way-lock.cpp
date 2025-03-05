#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int f[3];
int s[3];

bool check_with_f(const vector<int> &num){

    for(int i = 0; i < 3; i++){
        int gap = abs(f[i] - num[i]);
        gap = min(gap, abs(n - gap));

        if(gap > 2) return false;
    }

   return true;
}

bool check_with_s(const vector<int> &num){

    for(int i = 0; i < 3; i++){
        int gap = abs(s[i] - num[i]);
        gap = min(gap, abs(n - gap));

        if(gap > 2) return false;
    }
    
   return true;
}

int main() {
    // Please write your code here.
    cin >> n;
    
    for(int i = 0; i < 3; i++){
        cin >> f[i];
    }

    for(int i = 0; i < 3; i++){
        cin >> s[i];
    }

    // 모든 경우에
    // n을 가지고 만든 3자리 수에 대하여 
    vector<int> num(3, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                num[0] = i;
                num[1] = j;
                num[2] = k;
                // 할일을 한다.
                // 모든 자리에 대해 거리가 2여야한다.
                if(check_with_f(num) || check_with_s(num)) ans++;
            }
        }
    }

    cout << ans;
    return 0;
}