/*

문제: 14889 스타트와 링크

- 축구는 평일 오후에 하고 의무 참석도 아니다.
- 축구를 하기 위해 모인 사람은 총 N명, N은 짝수
- 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.

- 각 사람들에게 번호를 1부터 N까지로 배정했고, 능력치 조사
    ex) 능력치 Sij = i와 j가 같은 팀에 속했을 때, 팀에 더해지는 능력치
- 팀 능력치(해당 팀에 i와 j만 속해있다면) = Sij + Sji
- 축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 함.

- 입력: 첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수), 둘째 줄부터 N개의 줄에 S가 주어짐
        i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0, 나머지 1 <= Sij <= 100
- 출력: 스타트 팀과 링크 팀의 능력치의 차이의 최솟값

*/

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;
int **S;
int *team;
int leastGap = 100 * 10;

// 현재 팀의 능력치 합 구하기
int totalValue(int *thisTeam)
{
    int totalSum = 0;

    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i + 1; j < N / 2; j++)
        {
            int p_i = thisTeam[i];
            int p_j = thisTeam[j];
            totalSum += S[p_i][p_j] + S[p_j][p_i];
        }
    }

    return totalSum;
}

/*
 * |(1과 같은 팀이 될 경우의 능력치) - 그렇지 않은팀의 능력치|가 최소가 되는 값 찾기
 */
void solution(int team_idx, int now)
{

    // 종료조건 1. 선택할 갯수를 모두 담으면 그 이후로는 제외
    if (team_idx == N / 2)
    {
        // 1을 포함하지 않은 경우 구하기
        int *notTeam = new int[N / 2];
        int count = 0;
        for (int i = 1; i < N; i++)
        {
            if (find(team, team + N / 2, i) == (team + N / 2))
            {
                notTeam[count] = i;
                count++;

                if (count >= N / 2)
                {
                    break;
                }
            }
        }

        // 두 팀의 능력치 차이 절댓값 구하기
        int gap = abs(totalValue(team) - totalValue(notTeam));
        leastGap = leastGap > gap ? gap : leastGap;
        return;
    }

    // 종료조건 2. 주어진 값 이상인 경우 제외
    if (now >= N)
        return;

    // 현재 값이 선택될 경우
    team[team_idx] = now;
    solution(team_idx + 1, now + 1);

    // 현재값이 선택되지 않을 경우
    solution(team_idx, now + 1);
}

int main()
{
    // 1. 입력받기
    cin >> N;

    S = new int *[N];
    for (int i = 0; i < N; i++)
    {
        S[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    }

    /*
     * 2. 각 팀의 능력치 비교
     * 각 조합별 팀 능력치를 구하고
     * 그 중 최소값 선택
     */
    team = new int[N / 2];
    team[0] = 0; // 1번은 무조건 포함할 경우
    solution(1, 1);

    // 3. 출력
    cout << leastGap << endl;

    return 0;
}
