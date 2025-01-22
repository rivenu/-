#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
int cnt = 0;
int m, n;
queue<int> q;
int used[10000];
int step[10000];

int func(int num, int i)
{
    if (i == 1)
        return num + 1;
    if (i == 2)
        return num * 2;
    if (i == 3)
        return num * num;
}

int bfs()
{
    int num1, num2;
    while (!q.empty())
    {
        num1 = q.front();
        q.pop();
        for (int i = 1; i <= 3; i++)
        {
            num2 = func(num1, i);
            if (num2 == n)
                return step[num1] + 1;
            if (num2 <= n && !used[num2])
            {
                q.push(num2);
                used[num2] = 1;
                step[num2] = step[num1] + 1;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> m >> n;
    used[m] = 1;
    step[m] = 0;
    q.push(m);
    int res = bfs();

    cout << res;
}