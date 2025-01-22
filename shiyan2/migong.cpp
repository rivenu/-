#include <iostream>
#include <vector>
using namespace std;

char m[20][20];
int n;
int flag = 0;
int result[4];
int start_x, start_y, end_x, end_y;
int visited[20][20];

void Init();
void input();
void dfs(int x, int y);
void output();

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Init();
        input();
        dfs(start_x, start_y);
        result[i] = flag;
    }
    output();
}

void Init()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            visited[i][j] = 0;
            flag = 0;
        }
}

void input()
{
    cin >> start_x >> start_y >> end_x >> end_y;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            cin >> m[i][j];
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    if (x == end_x && end_y == y)
    {
        flag = 1;
        return;
    }

    if (m[x + 1][y] == '.' && x + 1 <= 19 && visited[x + 1][y] != 1)
    {
        dfs(x + 1, y);
    }
    if (m[x][y + 1] == '.' && y + 1 <= 19 && visited[x][y + 1] != 1)
    {
        dfs(x, y + 1);
    }
    if (m[x - 1][y] == '.' && x - 1 >= 0 && visited[x - 1][y] != 1)
    {
        dfs(x - 1, y);
    }
    if (m[x][y - 1] == '.' && y - 1 >= 0 && visited[x][y - 1] != 1)
    {
        dfs(x, y - 1);
    }
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        if (result[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}