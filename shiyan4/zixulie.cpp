#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char c1[100], c2[100];
int map[100][100];
int m, n;

void Init()
{
    cin.getline(c1, 100);
    cin.getline(c2, 100);
    m = strlen(c1);
    n = strlen(c2);
    for (int i = 0; i <= m; i++)
        map[0][i] = 0;

    for (int i = 0; i <= n; i++)
        map[i][0] = 0;
}

void dp()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (c1[i] == c2[j])
                map[i + 1][j + 1] = map[i][j] + 1;
            else
                map[i + 1][j + 1] = max(map[i + 1][j], map[i][j + 1]);
        }
}

int main()
{
    Init();
    dp();
    cout << map[m][n] << endl;

    
    return 0;
}
