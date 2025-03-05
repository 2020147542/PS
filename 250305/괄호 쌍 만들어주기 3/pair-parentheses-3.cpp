#include <iostream>
#include <string>
using namespace std;

string line;
int ans;

int main() {
    // Please write your code here.

    cin >> line;

    // 모든 경우에 대해
    // - 여는 괄호가 존재하는지 확인 
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ')') continue;

        // 할거 한다.
        // - 그거에 맞는 닫는 가로가 존재하는지 확인
        for(int j = i + 1; j < line.size(); j++){
            if(line[j] == ')') ans++;
        }
    }
    
    cout << ans;
    return 0;
}