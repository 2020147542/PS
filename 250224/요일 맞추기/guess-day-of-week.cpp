#include <iostream>
using namespace std;

int m1, d1, m2, d2;
int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Write your code here!
    int day1 = d1;
    for(int i = 0; i <= m1 - 2; i++){
        day1 += months[i];
    }

    int day2 = d2;
    for(int i = 0; i <= m2 - 2; i++){
        day2 += months[i];
    }

    int idx = (day2 - day1) % 7 + 7;
    cout << days[idx] << endl;

    return 0;
}