#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, m, c, res;
int arr[11][11];
vector<int> selected;
vector<int> max_line;
vector<int> cur_line;

void select(int i, int ncol, int ecol){
    if(ncol == ecol || ncol > n){
        int sum = 0;
        int wei = 0;

        for(int ele: selected){
            if (sum + ele > c) return;
            sum += ele;
            wei = wei + (ele * ele);
        }

        res = max(res, wei);
        return;
    }

    selected.push_back(arr[i][ncol]);
    select(i, ncol + 1, ecol);
    selected.pop_back();
    select(i, ncol + 1, ecol);
}

int result(int i, int k){
    res = INT_MIN;
    selected.clear();
    select(i, k, k+m);
    return res;
}

int main(){

    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        int max_a = INT_MIN, cur_max = INT_MIN;

        for(int k = 1; k <= n - m + 1; k++){
            max_a = max(max_a, result(i, k));

            int max_b = INT_MIN;
            for(int t = k + m; t <= n; t++){
                max_b = max(max_b, result(i, t));
            }

            cur_max = max(cur_max, max_a + max_b);
        }
        max_line.push_back(max_a);
        cur_line.push_back(cur_max);
    }

    sort(max_line.rbegin(), max_line.rend());
    sort(cur_line.rbegin(), cur_line.rend());

    if((max_line[0] + max_line[1]) >= cur_line[0]){
        cout << max_line[0] + max_line[1];
    }else{
        cout << cur_line[0];
    }

    return 0;
}