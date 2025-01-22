#include <iostream>
using namespace std;
int n;
char a[10];
char c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

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
            a[m] = c[i];
            dfs(m + 1);
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
}