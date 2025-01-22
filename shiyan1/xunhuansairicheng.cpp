#include <iostream>
using namespace std;
int a[300][300];
int n, m;

void print();
void Init();
void dfs(int m, int start);

int main()
{

    Init();
    dfs(0, n);
    print();
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << a[i][j] << " ";
            else
                cout << a[i][j] << endl;
        }
    }
}

void Init()
{
    cin >> m;
    n = 2;
    for (int i = 1; i < m; i++)
    {
        n *= 2;
    }
    for (int i = 0; i < n; i++)
        a[i][0] = i + 1;
}

void dfs(int start, int m)
{
    int mid = m / 2;
    if (m > 1)
    {
        dfs(start, mid);
        dfs(start + mid, mid);
        // ↘
        for (int i = start; i < start + m; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                a[i + mid][j + mid] = a[i][j];
            }
        }
        // ↗
        for (int i = start + mid; i < start + m; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                a[i - mid][j + mid] = a[i][j];
            }
        }
    }
}