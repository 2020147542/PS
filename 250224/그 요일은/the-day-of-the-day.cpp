#include <iostream>
using namespace std;

int m1, d1, m2, d2, cnt;
char a[3];
int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main(){
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> a;

    for(int i = 0; i < 7; i++){
        cnt++;
        if(days[i] == a) break;
    }

    int day1 = d1;
    for(int i = 0; i <= m1 - 2; i++){
        day1 += months[i]; // 무조건 월요일
    }

    int day2 = d2;
    for(int i = 0; i <= m2 - 2; i++){
        day2 += months[i];
    }

    cout <<  (day2 - day1 + cnt) / 7 << endl;

    return 0;
}