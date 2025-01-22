#include <iostream>
using namespace std;
int n;
char a[10];
char c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
int used[10] = {0};

void Init_used()
{
    for (int i = 0; i < n; i++)
        used[i] = 0;
}

void dfs(int m)
{
    if (m == n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                a[m] = c[i];
                dfs(m + 1);
                used[i] = 0; // 重置used[i]，以便字符可以被再次使用
            }
        }
    }
}

int main()
{
    cin >> n;
    Init_used();
    dfs(0);
}