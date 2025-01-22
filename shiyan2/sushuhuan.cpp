#include <iostream>
#include <math.h>
using namespace std;

int a[21];
int used[21];
int flag = 0;
void dfs(int m);
int is_prime(int m);

int main()
{
    a[1] = 1;
    used[1] = 1;
    dfs(2);
    return 0;
}

int is_prime(int m)
{
    int i;
    if (m < 3)
        return 0;
    else
    {
        for (i = 2; i <= sqrt(m); i++)
        {
            if (m % i == 0)
            {
                return 0;
                break;
            }
        }
    }
    return 1;
}

void dfs(int m)
{
    if (flag == 1)
        return;
    if (m == 21 && is_prime(a[1] + a[20]))
    {
        for (int i = 1; i <= 20; i++)
            cout << a[i] << ' ';
        flag = 1;
        return;
    }
    else
    {
        for (int i = 2; i <= 20; i++)
        {
            if (used[i] == 0)
            {
                a[m] = i;
                used[i] = 1;
                if (is_prime(a[m] + a[m - 1]))
                {
                    dfs(m + 1);
                }
                used[i] = 0;
            }
        }
    }
}