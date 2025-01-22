#include <iostream>
#include <vector>
using namespace std;

int n;
char a[5][5];
int pend = 1;
int now;
int maxn;
vector<int> result;

void input();
void dfs(int m);
void output();
bool can_place(int m);

int main()
{
    while (1)
    {
        input();
        if (!pend)
            break;
        now = maxn = 0;
        dfs(1);
        result.push_back(maxn);
    }
    output();
}

void input()
{
    cin >> n;
    if (n == 0)
    {
        pend = 0;
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
}

bool can_place(int m)
{
    int x = (m - 1) / n + 1; // 改正坐标计算
    int y = (m - 1) % n + 1; // 改正坐标计算
    if (a[x][y] == 'X')
        return false;
    
    // 向左搜
    for (int i = y - 1; i > 0; i--)
    {
        if (a[x][i] == '#') return false;
        if (a[x][i] == 'X') break;
    }

    // 向上搜
    for (int i = x - 1; i > 0; i--)
    {
        if (a[i][y] == '#') return false;
        if (a[i][y] == 'X') break;
    }
    
    return true;
}

void dfs(int m)
{
    if (m == n * n + 1)
    {
        maxn = max(maxn, now);
        return; // 增加返回以避免进一步递归
    }
    
    // 在当前格子可以放置时
    if (can_place(m))
    {
        a[(m - 1) / n + 1][(m - 1) % n + 1] = '#'; // 更新为 '#'
        now++;
        dfs(m + 1); // 尝试下一个格子
        now--;
        a[(m - 1) / n + 1][(m - 1) % n + 1] = '.'; // 恢复原状态
    }
    
    // 不放置棋子，继续递归
    dfs(m + 1);
}

void output()
{
    for (const auto& res : result)
    {
        cout << res << endl;
    }
}
