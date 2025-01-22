#include <iostream>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int m, n;
int start[2];
int endd[2];
int map[21][21];
bool cnt = false;
int visited[21][21];

bool isPath(int x, int y)
{
    return x >= 0 && x <n && visited[x][y] == 0 && y >= 0 && y < m&&map[x][y]!=1;
}

void search(int x, int y)
{
    visited[x][y] = 1;
    if (x == endd[0] && y == endd[1])
    {
        cnt = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isPath(nx, ny))
        {
            search(nx, ny);
        }
    }
}

int main()
{
    cin >> m >> n;
    cin >> start[0] >> start[1];
    cin >> endd[0] >> endd[1];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    search(start[0], start[1]);
    if (cnt)
        cout << "Yes";
    else
        cout << "No";
}