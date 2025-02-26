#include <iostream>
using namespace std;

int m1, d1, m2, d2, cnt = 1; // 시작일 포함이므로 1로 시작
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    cin >> m1 >> d1 >> m2 >> d2;

    while(m1 != m2 || d1 != d2){
        d1++;
        cnt++;

        if(d1 > months[m1]){
            d1 = 1;
            m1++;
        }
    }

    cout << cnt;
    return 0;
}