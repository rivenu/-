#include <iostream>
using namespace std;

int A[10];
int n = 8;
int cnt = 0;

void disp()
{
    cnt++;
    cout << "No " << cnt << ":" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (A[i] == j)
                cout << "A";
            else
                cout << ".";
            if (j == n)
                cout << endl;
        }
}

bool can_place(int x, int y)
{
    for (int i = 1; i < x; i++)
        if (A[i] == y || abs(x - i) == abs(y - A[i]))
            return false;
    return true;
}

void search(int i)
{
    if (i > n)
        disp();
    for (int j = 1; j <= n; j++)
    {
        if (can_place(i, j))
        {
            A[i] = j;
            search(i + 1);
            A[i] = 0;
        }
    }
}

int main()
{
    search(1);
}