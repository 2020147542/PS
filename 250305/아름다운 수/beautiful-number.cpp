#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int> seq;

bool isPretty(){
    for(int i = 0; i < seq.size(); i += seq[i]){

        if(i + seq[i] > n) return false;

        for(int j = i; j < i + seq[i]; j++){
            if(seq[j] != seq[i]) {
                return false;
            }
        }
    }

    return true;
}

void check(int idx){
    if(idx == n+1){
        // 아름다운 수 확인
        if(isPretty()) ans++;
        return;
    }

    for(int i = 1; i <= 4; i++){
        seq.push_back(i);
        check(idx+1);
        seq.pop_back();
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    check(1);
    cout << ans << '\n';
    return 0;
}
