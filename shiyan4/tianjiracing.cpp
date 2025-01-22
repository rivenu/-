#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int tian[100], qi[100];

int main()
{
    while (cin >> n && n != 0)
    {
        memset(tian,0,sizeof(tian));
        memset(qi,0,sizeof(qi));
        for (int i = 1; i <= n; i++)
            cin >> tian[i];
        for (int j = 1; j <= n; j++)
            cin >> qi[j];
        sort(tian + 1, tian + 1 + n);
        sort(qi + 1, qi + 1 + n);
        int up_tian = n, up_qi = n, down_tian = 1, down_qi = 1, win = 0, lose = 0;
        while (up_tian >= down_tian)
        {
            if (tian[up_tian] > qi[up_qi])
            {
                up_tian--, up_qi--, win++;
            }

            else
            {
                if (tian[down_tian] > qi[down_qi])
                {
                    down_tian++, down_qi++, win++;
                }

                else if(tian[down_tian]<qi[up_qi])
                {
                    down_tian++, up_qi--, lose++;
                }
                else{
                    down_tian++, up_qi--;
                }
            }
        }
        cout<<win-lose<<endl;
    }
}