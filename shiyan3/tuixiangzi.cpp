#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int mx, my;
    int bx, by;
    bool use; // 判断该节点能否存在
}; // m为木乃伊，n为人,use为这种情况是否出现过,x行y列

queue<node> q;
int mstart_x, mstart_y, bstart_x, bstart_y, end_x, end_y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int used[11][11][11][11]; // bx,by,mx,my
int step[11][11][11][11]; // bx,by,mx,my
int maze[11][11];
void Init();
int bfs();

int main()
{
    Init();
    cout << bfs() << endl;
}

node move(node now, int i)
{
    node next;

    next.bx = now.bx; // 箱子位置暂时不动
    next.by = now.by;

    next.mx = now.mx + dx[i]; // 人向i方向移动一格
    next.my = now.my + dy[i];

    if (next.mx == next.bx && next.my == next.by) // 若此时人与箱子位置重叠
    {
        next.bx += dx[i]; // 那么箱子也要向i方向移动一格
        next.by += dy[i];
    }

    // 判断新节点next是否有效

    next.use = false; // 初始为无效

    if (next.bx >= 1 && next.bx <= 10 && next.by >= 1 && next.by <= 10 && next.mx >= 1 && next.mx <= 10 && next.my >= 1 && next.my <= 10) // 箱子&&人不越界
    {
        if (maze[next.bx][next.by] == 0     // 箱子所在位置不是墙
            && maze[next.mx][next.my] == 0) //&&人所在位置不是墙
        {
            if (used[next.bx][next.by][next.mx][next.my] == 0) // 节点不重复
            {
                next.use = true; // 同时满足上述条件，该节点才有效

                // 标记“到达过”和“到达步数”
                used[next.bx][next.by][next.mx][next.my] = 1;
                step[next.bx][next.by][next.mx][next.my] =
                    1 + step[now.bx][now.by][now.mx][now.my];
            }
        }
    }

    return next; // 返回新节点
}

int bfs()
{
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            node next = move(now, i);
            if (next.use)
            {
                if (next.bx == end_x && next.by == end_y)
                    return step[next.bx][next.by][next.mx][next.my];
                else
                    q.push(next);
            }
        }
    }
    return -1;
}

void Init()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            maze[i][j] = cin.get() - '0';
            if (maze[i][j] == 2)
            {
                bstart_x = i, bstart_y = j;
                maze[i][j] = 0;
            }
            if (maze[i][j] == 3)
            {
                end_x = i, end_y = j;
                maze[i][j] = 0;
            }
            if (maze[i][j] == 4)
            {
                mstart_x = i, mstart_y = j;
                maze[i][j] = 0;
            }
        }
        cin.get();
    }
    node temp;
    temp.mx = mstart_x;
    temp.my = mstart_y;
    temp.bx = bstart_x;
    temp.by = bstart_y;
    q.push(temp);
}
