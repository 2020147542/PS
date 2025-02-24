#include <iostream>
#include <stack>
using namespace std;

int a, b, res;
string n;
stack<int> ans;

int main() {
    cin >> a >> b;
    cin >> n;

    // Write your code here!
    for(char c : n){
        res = res * a + c - '0';
    }

    while(true){
        ans.push(res % b);

        if(res < b) break;
        res /= b;
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }

    return 0;
}