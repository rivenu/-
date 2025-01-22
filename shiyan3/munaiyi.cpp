#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int mx, my;
    int nx, ny;
    int use;
}; // m为木乃伊，n为人,use为这种情况是否出现过,x行y列

int vis[7][7][7][7]; // 前两个为人x,y，后两个为木乃伊x,y
queue<node> q;
int maze[8][8][2]; // 只记录墙的位置,0为下，1为右
int nstart_x, nstart_y, mstart_x, mstart_y, end_x, end_y;
int n; // 墙的数量

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void Init();
bool bfs();
bool iswall(int x, int y, int i);
node move(node now, int i);

int main()
{
    Init();
    if (bfs())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

bool iswall(int x, int y, int i)
{
    switch (i)
    {
    case 0: // 向左走
        return maze[x][y - 1][1];

    case 1: // 向下走
        return maze[x][y][0];

    case 2: // 向右走
        return maze[x][y][1];

    case 3: // 向上走
        return maze[x - 1][y][0];
    }
    return false;
}

node move(node now, int i)
{
    node next;
    next.nx = now.nx + dx[i];
    next.ny = now.ny + dy[i];
    if (next.ny < 0 || next.ny > 5 || next.nx < 0 || next.nx > 5 || iswall(now.nx, now.ny, i))
    {
        next.use = false;
        return next;
    }
    int step = 2;
    next.mx = now.mx, next.my = now.my;
    while (step--)
    {
        if (next.ny > next.my && !iswall(next.mx, next.my, 2))
        {
            next.my++;
        }
        else if (next.ny < next.my && !iswall(next.mx, next.my, 0))
        {
            next.my--;
        }
        else if (next.ny == next.my)
        {
            if (next.nx > next.mx && !iswall(next.mx, next.my, 1))
            {
                next.mx++;
            }
            else if (next.nx < next.mx && !iswall(next.mx, next.my, 3))
            {
                next.mx--;
            }
            else if (next.nx == next.mx)
            {
                next.use = false;
                return next;
            }
        }
    }
    if (vis[next.nx][next.ny][next.mx][next.my])
    {
        next.use = false;
    }
    else
    {
        next.use = true;
        vis[next.nx][next.ny][next.mx][next.my] = 1;
    }
    return next;
}

bool bfs()
{
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            node next = move(now, i);
            if (next.use == true)
            {
                if (next.nx == end_x && next.ny == end_y)
                    return true;
                q.push(next);
            }
        }
    }
    return false;
}

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        maze[x][y][w] = 1;
    }
    cin >> mstart_x >> mstart_y >> nstart_x >> nstart_y >> end_x >> end_y;
    node temp;
    temp.mx = mstart_x;
    temp.my = mstart_y;
    temp.nx = nstart_x;
    temp.ny = nstart_y;
    vis[nstart_x][nstart_y][mstart_x][mstart_y] = 1;
    q.push(temp);
}
