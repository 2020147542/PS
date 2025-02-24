#include <iostream>
using namespace std;

int m1, d1, m2, d2, cnt;
int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
string a;

int main(){
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> a;

    for(int i = 0; i < 7; i++){
        if(days[i] == a) break; // 월요일부터 +1
        cnt++;
    }

    int day1 = d1 + cnt;
    for(int i = 0; i <= m1 - 2; i++){
        day1 += months[i]; // 무조건 월요일
    }

    int day2 = d2;
    for(int i = 0; i <= m2 - 2; i++){
        day2 += months[i];
    }

    int r = day2 < day1 ? 0 : 1;
    cout << (day2 - day1) / 7 + r << endl;

    return 0;
}