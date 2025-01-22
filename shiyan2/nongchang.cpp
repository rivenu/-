#include <iostream>

using namespace std;
struct point
{
    int up, down, left, right;
    int visit;
    char ch;
};

point map[100][100];
int m, n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 向右，向左，向上，向下

void input();
void dfs(int y, int x);
bool can_connect(int x, int y, int nx, int ny);

int main()
{
    while (cin >> m >> n && m != -1 && n != -1)
    {
        int cnt = 0;
        input();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (map[i][j].visit == 0)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        cout << cnt << endl;
    }
}

bool can_connect(int x, int y, int nx, int ny)

{
    if (nx >= 0 && nx < m && ny >= 0 && ny < n)
    {
        if (!map[ny][nx].visit)
        {
            if (nx == x && ny == y - 1 && map[y][x].up && map[ny][nx].down)
                return true;
            if (nx == x && ny == y + 1 && map[y][x].down && map[ny][nx].up)
                return true;
            if (nx == x - 1 && ny == y && map[y][x].left && map[ny][nx].right)
                return true;
            if (nx == x + 1 && ny == y && map[y][x].right && map[ny][nx].left)
                return true;
        }
    }
    return false;
}

void dfs(int y, int x)
{
    map[y][x].visit = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (can_connect(x, y, nx, ny))
        {
            dfs(ny, nx);
        }
    }
}

void input()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j].ch;
            map[i][j].visit = 0;
            map[i][j].down = 0;
            map[i][j].up = 0;
            map[i][j].right = 0;
            map[i][j].left = 0;
            switch (map[i][j].ch)
            {
            case 'A':
            {
                map[i][j].left = 1;
                map[i][j].up = 1;
                break;
            }
            case 'B':
            {
                map[i][j].right = 1;
                map[i][j].up = 1;
                break;
            }
            case 'C':
            {
                map[i][j].left = 1;
                map[i][j].down = 1;
                break;
            }
            case 'D':
            {
                map[i][j].right = 1;
                map[i][j].down = 1;
                break;
            }
            case 'E':
            {
                map[i][j].up = 1;
                map[i][j].down = 1;
                break;
            }
            case 'F':
            {
                map[i][j].left = 1;
                map[i][j].right = 1;
                break;
            }

            case 'G':
            {
                map[i][j].left = 1;
                map[i][j].right = 1;
                map[i][j].up = 1;
                break;
            }

            case 'H':
            {
                map[i][j].left = 1;
                map[i][j].down = 1;
                map[i][j].up = 1;
                break;
            }
            case 'I':
            {
                map[i][j].left = 1;
                map[i][j].down = 1;
                map[i][j].right = 1;
                break;
            }
            case 'J':
            {
                map[i][j].up = 1;
                map[i][j].down = 1;
                map[i][j].right = 1;
                break;
            }
            case 'K':
            {
                map[i][j].up = 1;
                map[i][j].down = 1;
                map[i][j].right = 1;
                map[i][j].left = 1;
                break;
            }
            }
        }
}