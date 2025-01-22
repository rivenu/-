#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
int n, c;
int wi[12], pi[12]; // wi重量,pi价值
int pend = 1;
int f[12][120];
// void clear();
void input();
void dfs();
void output();
int main()
{
    while (1)
    {
        input();
        if (!pend)
            break;
        dfs();
        result.push_back(f[n][c]);
    }
    output();
}

void dfs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= c; j++)
        {
            f[i][j] = f[i - 1][j]; // 不选第i个物品；

            if (j >= wi[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - wi[i]] + pi[i]);
        }
}

void output()
{
    vector<int>::iterator itBegin = result.begin();
    vector<int>::iterator itEnd = result.end();
    for (; itBegin != itEnd; itBegin++)
        cout << *(itBegin) << endl;
}

void input()
{
    cin >> n >> c;
    if (n == 0 && c == 0)
    {
        pend = 0;
        return;
    }
    for (int i = 1; i <= n; i++)
        cin >> wi[i];
    for (int i = 1; i <= n; i++)
        cin >> pi[i];
}

// void clear()
// {
//     n = 0;
//     c = 0;
//     for (int i = 0; i < 11; i++)
//     {
//         wi[i] = 0;
//         pi[i] = 0;
//     }
// }