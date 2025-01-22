#include <iostream>
#include <cstring>
using namespace std;
// Tom吃掉最后一颗，1Jerry先取，0Tom先取
int fos[1001][1001]; //[当前剩余多少颗][最多取多少颗]=谁先手
int n;
int dp(int res, int k)
{
    if (res == 1)
    {
        fos[res][k] = 0;
        return 0;
    }
    else if (fos[res][k] >= 0)
    {
        return fos[res][k];
    }
    else
    {
        int temp = 1;
        for (int i = 1; i <= k && i <= res; i++)
        {
            fos[res - i][min(res, 2 * i)] = dp(res - i, min(res , 2 * i));
            temp *= fos[res - i][min(res , 2 * i)];
            if (temp == 0)
                break;
        }//取完i颗后如果一直都是自己赢则由别人来取这i颗，如果自己取完i颗后存在别人赢的情况则由自己来取这i颗
        fos[res][k] = 1 - temp;
        return fos[res][k];
    }
}

int main()
{
    while (cin >> n && n != 0)
    {
        memset(fos, -1, sizeof(fos));
        cout << dp(n,1) << endl;
    }
}