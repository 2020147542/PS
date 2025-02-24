#include <iostream>
#include <stack>

using namespace std;

string N;
int res;
stack<int> ans;

int main() {
    cin >> N;

    for(char c : N){
        res = res * 2 + c - '0';
    }

    res *= 17;

    while(true){
        ans.push(res % 2);

        if(res <= 1) break;
        res /= 2;
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }

    return 0;
}