#include <iostream>
using namespace std;

string a;
int cnt;

int main() {
    // Please write your code here.
    cin >> a;
    // 모든 경우에 대해
    // 연속한 ((가 나오는 모든 경우에 대해
    for(int i = 1; i < a.size(); i++){
        if(a[i-1] == '(' && a[i] == '('){

            // 할거 하자
            // 연속한 ))가 나오는 수를 세자
            for(int j = i+2; j < a.size(); j++){
                if(a[j-1] == ')' && a[j] == ')') cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}