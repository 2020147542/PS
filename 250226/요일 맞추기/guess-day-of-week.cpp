#include <iostream>
using namespace std;

int m1, d1;
int m2, d2;
int cnt;
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
bool isReversed; // 두번째로 주어진 날짜가 더 먼저일 경우

int main(){

    cin >> m1 >> d1 >> m2 >> d2;

    if(m1 > m2 || (m1 == m2 && d1 > d2)) isReversed = true;

    while(m1 != m2 || d1 != d2){
        if(isReversed){
            d1--;
            cnt--;

            if(d1 <= 0){
                m1--;
                d1 = months[m1];
            }

        } else{
            d1++;
            cnt++;
            
            if(d1 > months[m1]){
                m1++;
                d1 = 1;
            }
        }
    }

    if(cnt * 7 < 0){
        cout << days[(cnt % 7) + 7];
    }else{
        cout << days[cnt % 7];
    }

    return 0;
}