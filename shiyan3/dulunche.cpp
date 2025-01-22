#include <iostream>
#include <queue>
using namespace std;
struct point
{
    int x, y, dir, col, ti;
    point(int _x, int _y, int _dir, int _col, int _ti)
    {
        x = _x;
        y = _y;
        dir = _dir;
        col = _col;
        ti = _ti;
    }
};
char map[21][21];
queue<point> q;
int start_x, start_y, end_x, end_y;
char start_col, start_dir, end_col;
int dirxy[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}}; // 第一个加在x上，第二个加在y上，右，下，左，上
bool visit[21][21][4][5];                         // y,x,dir,col
void input();
int bfs();
int colTonum(char c);
int dirTonum(char c);

int main()
{
    input();
    cout << bfs();
}

void input()
{
    cin >> start_y >> start_x >> start_col >> start_dir >> end_y >> end_x >> end_col;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= 20; j++)
        {
            cin >> map[i][j];
        }
    int temp_dir, temp_col;
    temp_dir = dirTonum(start_dir);
    temp_col = colTonum(start_col);
    q.push(point(start_x, start_y, temp_dir, temp_col, 0));
}

int bfs()
{
    while (!q.empty())
    {
        point np = q.front();
        q.pop();
        int x = np.x, y = np.y, dir = np.dir, col = np.col, ti = np.ti;
        if (x == end_x && y == end_y && col == colTonum(end_col))
            return ti;
        if (visit[y][x][dir][col])
            continue;
        visit[y][x][dir][col] = 1;
        ti++;
        int nx = x + dirxy[0][dir];
        int ny = y + dirxy[1][dir];
        if (nx > 0 && nx < 21 && ny > 0 && ny < 21 && map[ny][nx] == '.')
        {
            q.push(point(nx, ny, dir, (col + 1) % 5, ti));
        }
        q.push(point(x, y, (dir + 1) % 4, col, ti));
        q.push(point(x, y, (dir + 3) % 4, col, ti));
    }
    return -1;
}

int colTonum(char c)
{ // RYBWG
    if (c == 'R')
        return 0;
    if (c == 'Y')
        return 1;
    if (c == 'B')
        return 2;
    if (c == 'W')
        return 3;
    if (c == 'G')
        return 4;
}

int dirTonum(char c)
{ // 右下左上
    if (c == 'E')
        return 0;
    if (c == 'S')
        return 1;
    if (c == 'W')
        return 2;
    if (c == 'N')
        return 3;
}