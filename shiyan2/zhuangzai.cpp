#include <iostream>
#include <vector>
using namespace std;

vector<int> result;
int c1, c2, n;
int wi[100]; // wt为第n个样例的总重量
int pend = 1;
int f[10][100]; // 前i个货物装到重量为j的船上的最大重量
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
        int total = 0;
        for (int i = 1; i <= n; i++)
            total += wi[i];
        if (total - f[n][c1] <= c2)
            result.push_back(1);
        else
            result.push_back(0);
    }
    output();
}

void output()
{
    vector<int>::iterator itBegin = result.begin();
    vector<int>::iterator itEnd = result.end();
    for (; itBegin != itEnd; itBegin++)
    {
        if (*itBegin)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

void dfs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= c1; j++)
        {
            f[i][j] = f[i - 1][j]; // 不装第i种
            if (j >= wi[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - wi[i]] + wi[i]);
        }
}

void input()
{
    cin >> c1 >> c2 >> n;
    if (n == 0)
    {
        pend = 0;
        return;
    }
    for (int i = 1; i <= n; i++)
        cin >> wi[i];
}