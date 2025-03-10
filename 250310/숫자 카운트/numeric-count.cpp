#include <iostream>
#include <set>
using namespace std;

int n;
set<int> a;

void find(int b, int cnt1, int cnt2){

    // cnt1 = b의 3자리 숫자들중 a와 동일한 위치에 위치한 경우
    // cnt2 = b의 3자리 숫자들중 a에 존재하지만 다른 위치에 위치한 경우

    int digit[3] = {b/100, (b/10)%10, b% 10};
    int c1 = 0, c2 = 0;

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i == j) continue;

            for(int k = 1; k <= 9; k++){
                if(j == k) continue;

                for(int idx = 0; idx < 3; idx++){
                    if(i == digit[idx]){
                        if(idx == 0) c1++;
                        else c2++;
                    }
                    if(j == digit[idx]){
                        if(idx == 0) c1++;
                        else c2++;
                    }
                    if(k == digit[idx]){
                        if(idx == 0) c1++;
                        else c2++;
                    }
                }

                if(c1 == cnt1 && c2 == cnt2) {
                   a.insert(i*100 + j *10 + k);
                }
            }
        }
    }
}

int main() {

    cin >> n;
    for(int i = 0; i < n; i++){
        int b, cnt1, cnt2;
        cin >> b >> cnt1 >> cnt2;

        find(b, cnt1, cnt2);
    }

    cout << a.size();
    return 0;
}