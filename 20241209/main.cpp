/*

문제: 2231번 분해합

- 어떤 자연수 N이 있을 때, 그 자연수 N의 분해합(M) = N과 N을 이루는 각 자리수의 합을 의미
- 이때, N을 M의 생성자라 함
    ex) 245의 분해합 = 2+4+5+245 = 256, 256의 생성자 = 245
- 어떤 분해합의 경우 생성자가 없을 수 도 있음. 반대로 생성자가 여러 개인 분해합도 있을 수 있음

입력 : 자연수(=분해합) N( 1 < N <= 1,000,000 )
출력 : N의 가장 작은 생성자, 생성자가 없는 경우 0 출력

1차 문제 해석 소요시간 : 16분
총 소요시간: 1시간 10분
*/

#include <iostream>
#include <string>

using namespace std;

int findConstructor(int i)
{
    string n = to_string(i);
    int totalSum = i;

    for (int k = 0; k < n.length(); k++)
    {
        totalSum += n[k] - '0';
    }

    return totalSum;
};

int main()
{

    string N;

    // 1. string n을 입력 받음
    cin >> N;
    int n = stoi(N);

    /*  2. 생성자 구하기
        n의 자릿수 구하기 = k
        자릿수의 최대합 = k * 9
        n - k * 9  부터 n - 1까지 커지면서 구해보기
    */
    int k = N.length();
    int maxGap = k * 9;

    for (int i = n - maxGap; i < n; i++)
    {
        if (n == findConstructor(i))
        {
            cout << i << endl;
            return 0;
        }
    }

    // 생성자가 없는 경우 0을 출력한다.
    cout << 0 << endl;

    return 0;
}
