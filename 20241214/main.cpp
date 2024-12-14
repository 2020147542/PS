/*

문제: 1051번 숫자 정사각형

- NXM 직사각형 존재
- 각 칸에는 한자리 숫자가 적혀있음
- 직사각형의 꼭짓점에 있는 수가 모두 같은 정사각형 중, 가장 큰 경우를 찾는 프로그램 찾기
- 단, 정사각형은 행 Or 열에 평행 해야함

입력 : N, M 주어짐(1 ~ 50), 둘째 줄부터 직사각형이 한 줄 씩 주어짐
출력 : 가능한 정사각형의 최대 크기를 출력

소요시간: 1시간

*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> rect;

/*
 * 전달받은 인자만큼의 크기의 정사각형 모서리가 모두 같은지 확인
 * 같다면 해당 정사각형의 한 변의 길이 return
 * 그렇지 않은 경우 -1 return
 */
int checkIfAnswer(int size)
{

    for (int i = 0; i + size <= N; i++)
    {
        for (int j = 0; j + size <= M; j++)
        {
            char leftTop = rect[i][j];
            char leftBottom = rect[i + size - 1][j];
            char rightTop = rect[i][j + size - 1];
            char rightBottom = rect[i + size - 1][j + size - 1];

            if (leftTop == leftBottom && leftBottom == rightTop && rightTop == rightBottom)
            {
                return size;
            }
        }
    }

    return -1;
}

int main()
{
    // 1. 입력받기
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string lineString;
        cin >> lineString;

        rect.push_back(lineString);
    }

    /*
     * 2. 꼭짓점이 모두 같은 정사각형의 최대 크기 구하기
     * 나올 수 있는 최대 크기의 정사각형 구하기
     * 가장 큰 정사각형부터 꼭짓점이 존재할 수 있는 2*2까지 하나씩 돌아가면서 꼭짓점 같은지 확인
     * 만족하는 정사각형이 나오면 바로 그 정사각형의 크기 출력
     * 아닌 경우, 무조건 1 출력
     */
    int maxSquare = min(N, M);
    for (int i = maxSquare; i > 1; i--)
    {
        int result = checkIfAnswer(i);

        if (result != -1)
        {
            cout << result * result << endl;

            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}