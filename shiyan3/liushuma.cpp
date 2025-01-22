#include <iostream>
#include <queue>
using namespace std;

int a[7]; // 目标数组
int b[7]; // 当前数组
int use[1000000];
queue<int> q;
void alpha();
void beta();
int num(int *a);
void Init();
int bfs();
void numToarr(int n);

int main()
{
    while (cin >> a[1])
    {
        Init();
        int ans = 0;
        ans = bfs();
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int bfs()
{

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        numToarr(u);
        if (u == num(a))
            return 1;
        for (int i = 0; i < 2; i++)
        {
            int prev[7];          // 保存当前状态
            copy(b, b + 7, prev); // 复制当前状态

            if (i)
                alpha();
            else
                beta();

            int n = num(b);
            if (!use[n])
            {
                q.push(n);
                use[n] = 1;
            }

            // 还原回之前的状态
            copy(prev, prev + 7, b);
        }
    }
    return 0;
}

void Init()
{
    for (int i = 0; i < 1000000; i++)
        use[i] = 0;
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= 6; i++)
        b[i] = i;
    for (int i = 2; i <= 6; i++)
        cin >> a[i];
    q.push(num(b));
}

int num(int *a)
{
    return (a[1] * 100000 + a[2] * 10000 + a[3] * 1000 + a[4] * 100 + a[5] * 10 + a[6]);
}

void alpha()
{
    int c[7];
    c[2] = b[1];
    c[5] = b[2];
    c[4] = b[5];
    c[1] = b[4];
    c[3] = b[3];
    c[6] = b[6];
    for (int i = 1; i <= 6; i++)
        b[i] = c[i];
}

void beta()
{
    int c[7];
    c[3] = b[2];
    c[6] = b[3];
    c[5] = b[6];
    c[2] = b[5];
    c[1] = b[1];
    c[4] = b[4];
    for (int i = 1; i <= 6; i++)
        b[i] = c[i];
}

void numToarr(int n)
{
    b[1] = n / 100000;
    b[2] = (n / 10000) % 10;
    b[3] = (n / 1000) % 10;
    b[4] = (n / 100) % 10;
    b[5] = (n / 10) % 10;
    b[6] = n % 10;
}