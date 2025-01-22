#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int x, y;
    int t, et; // 剩余时间,eat消化的剩余时间
};

queue<node> q;
char maze[201][201];
int vis[201][201];
int t, p;
int m, n;
int start_x, start_y, end_x, end_y, eat_x, eat_y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void Init();
int bfs();

int main()
{
    Init();
    cout << bfs() << endl;
}

int bfs() {
    while (!q.empty()) {
        int nx, ny;
        node now = q.front();
        q.pop();
        
        nx = now.x; // Initialize nx and ny
        ny = now.y;

        for (int i = 0; i < 4; i++) {
            node next;
            int px = nx + dx[i];
            int py = ny + dy[i];

            if (px >= 1 && px <= m && py >= 1 && py <= n && !vis[px][py] && maze[px][py] != '#' && now.t - 1 > 0) {
                if (px == eat_x && py == eat_y && now.et == 0) {
                    next.x = start_x; // This logic should be reconsidered
                    next.y = start_y;
                    next.et = t;
                    next.t = now.t - 1;
                    memset(vis, 0, sizeof(vis)); // Clear visited array when eaten
                } else {
                    next.t = now.t - 1;
                    if (now.et != 0)
                        next.et = now.et - 1; // Decrease eat time correctly
                    next.x = px;
                    next.y = py;
                    vis[px][py] = 1; // Mark as visited
                    q.push(next);
                }

                if (px == end_x && py == end_y)
                    return p - next.t + 1; // Make sure to return correct timing
            }
        }
    }
    return -1; // Return -1 if no path found
}


void Init()
{
    cin >> m >> n >> t;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '!')
            {
                start_x = i;
                start_y = j;
                vis[i][j] = 1;
            }
            if (maze[i][j] == '+')
            {
                end_x = i;
                end_y = j;
            }
            if (maze[i][j] == '@')
            {
                eat_x = i;
                eat_y = j;
            }
        }
    node temp;
    temp.x = start_x;
    temp.y = start_y;
    temp.t = p;
    temp.et = 0;
    q.push(temp);
}