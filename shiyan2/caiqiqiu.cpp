#include <iostream>
#include <vector>
using namespace std;

int a, b;            // 两个小朋友的数
bool a_flag, b_flag; // 两个小朋友真假
int flag = 1;
int vis[101];

void input();
bool dfs(int n, int k);
void Init();
int main()
{
    while (1)
    {
        input();
        Init();
        if (!flag)
            break;
        a_flag = dfs(a, 100);
        b_flag = dfs(b, 100);
        if ((a_flag == true && b_flag == true) || (a_flag == false && b_flag == false))
            cout << max(a, b) << endl;
        if ((a_flag == true && b_flag == false))
            cout << a << endl;
        if ((a_flag == false && b_flag == true))
            cout << b << endl;
    }
}

void input()
{
    cin >> a >> b;
    if (a == 0 && b == 0)
        flag = 0;
}

bool dfs(int n, int k)
{
    if (n == 1)
    {
        return true;
    }

    if (k > 1)
    {
        if (n % k == 0 && vis[k] == 0)
        {
            vis[k] = 1;
            return dfs(n / k, k - 1);
        }
        else
        {
            return dfs(n, k - 1);
        }
    }
    return false;
}

void Init()
{

    for (int i = 0; i < 101; i++)
        vis[i] = 0;
}