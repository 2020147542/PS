/*

문제: 1463번 1로 만들기

- 0.15초, 128MB 제한
- 정수 X에 사용할 수 있는 연산은 다음과 같이 3가지
    - 3으로 나누어 떨어지면 3으로 나누기
    - 2로 나누어 떨어지면 2로 나누기
    - 1 빼기
- 위 3가지 연산을 최소한 사용해서 X를 1로 만드려고 함!

- 입력: 정수 N(1 <= N <= 10^6)
- 출력: 연산 횟수의 최솟값

*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N;

void dp(vector<int> &arr){
    for (int i = 4; i <= N; i++){
        int r3 = i % 3 == 0 ? i / 3 : 0;
        int r2 = i % 2 == 0 ? i / 2 : 0;
        int r1 = i - 1;

        arr[i] = min({arr[r3], arr[r2], arr[r1]}) + 1;
    }
}

int main() {
    cin >> N;

    vector<int> arr(N+1, 0);
    arr[0] = INT_MAX;
    arr[1] = 0; // 1->1
    arr[2] = 1; // 2->1
    arr[3] = 1; // 3->1

    dp(arr);
    cout << arr[N] << endl;

    return 0;
}
