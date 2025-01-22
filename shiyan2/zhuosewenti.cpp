#include <iostream>
using namespace std;
int n, r, m; // n个顶点和r条边，m种颜色

int gra[100][100];    // 各点之间的关系
int color[100] = {0}; // 0代表没颜色
void dfs(int a);
int num = 0;
bool iS_ok(int a);

int main()
{
    int temp1, temp2;
    cin >> n >> r >> m;
    for (int i = 0; i < r; i++)
    {
        cin >> temp1 >> temp2;
        gra[temp1][temp2] = 1;
        gra[temp2][temp1] = 1;
    }
    dfs(0);
    cout << num << endl;
}

bool iS_ok(int a)
{
    if (a == 0)
        return true;
    else
    {
        for (int i = 0; i < a ; i++)
            if (gra[a][i] && color[a] == color[i])
                return false;
    }
    return true;
}

void dfs(int a)
{
    if (a == n)
    {
        num++;
        return;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            color[a] = i;
            if (iS_ok(a))
                dfs(a + 1);
            color[a] = 0;
        }
    }
}