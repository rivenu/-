#include <iostream>
#include <queue>
using namespace std;
 
struct node {
	int x;
	int y;
    int z;
};
int m,n,k;
node start,target;
 
queue <node> q1; //广搜所用队列
 
int used[10][10][10]; //判重数组
int step[10][10][10];  //步数数组
// int bottle[3] = {8,5,3}
// int walk[8][3]={{-8,+5,+3},
//                 {-5,+5,0},
//                 {-3,0,+3},
//                 {+5,-5,0},
//                 {+2,-5,+3},
//                 {0,-3,+3},
//                 {+3,0,-3},
//                 {0,+3,-3}};
 
 
void input();   //输入
void init(node start);  //初始化
node moveto(node u,int diret);  //移动算法
int bfs();   //主算法
bool effective(node v);  //是否有效
bool istarget(node v);  //是否达到目标
 
int main()
{
    cin>>m>>n>>k;
    cin.get();
    input();
    init(start);
    cout<<bfs()<<endl;
    return 0;
}
 
void input()
{
    start.x = m;
    start.y = 0;
    start.z = 0;
    target.x = m/2;
    target.y = m/2;
    target.z = 0;
}
 
 
void init(node start)
{
    used[start.x][start.y][start.z] = 1;
    step[start.x][start.y][start.z] = 0;
    q1.push(start);
}
 
node moveto(node u,int i) //x倒入y中
{
    node v;
    switch (i)
    {
    case 1:
        v.x = u.x-(n-u.y);
        if(v.x>=0&&v.x<=m)
        {
            v.y = n;
        }
        else
        {
            v.x = 0;
            v.y = u.x+u.y;
        }
        v.z = u.z;
        break;
    case 2:
        v.x = u.x-(k-u.z);
        if(v.x>=0&&v.x<=m)
        {
            v.z = k;
        }
        else
        {
            v.x = 0;
            v.z = u.x+u.z;
        }
        v.y = u.y;
        break;
    case 3:
        v.y = 0;
        v.x = u.x + u.y;
        v.z = u.z;
        break;
    case 4:
        v.y = u.y-(k-u.z);
        if(v.y>=0&&v.y<=n)
        {
            v.z = k;
        }
        else
        {
            v.y = 0;
            v.z = u.y+u.z;
        }
        v.x = u.x;
        break;
    case 5:
        v.z = 0;
        v.x = u.x+u.z;
        v.y = u.y;
        break;
    case 6:
        v.z = u.z-(n-u.y);
        if(v.z>=0&&v.z<=k)
        {
            v.y = n;
        }
        else
        {
            v.z = 0;
            v.y = u.y+u.z;
        }
        v.x = u.x;
        break;
    default:
        break;
    }
    return v;
}
 
int bfs()
{
    while (!q1.empty())
    {
        //取出u
        node u,v;
        u = q1.front();
        q1.pop();
        for(int i=1;i<7;i++)
        {
            v = moveto(u,i);
            if(effective(v))
            {
                if(istarget(v))
                {
                    return step[u.x][u.y][u.z]+1;
                }
                used[v.x][v.y][v.z] = 1;
                step[v.x][v.y][v.z] = step[u.x][u.y][u.z]+1;
                q1.push(v);
            }
        }
    }
    return -1;
 
}
 
 
bool effective(node v)
{
    if(v.x>=0&&v.x<=m&&v.y>=0&&v.y<=n&&v.z>=0&&v.z<=k&&used[v.x][v.y][v.z]==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
 
 
 
 
 
 
bool istarget(node v)
{
    if(v.x == target.x&&v.y==target.y &&v.z == target.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}