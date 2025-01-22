#include <iostream>
#include <algorithm>
using namespace std;

int flag = 0;
int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
void condition()
{
    int sum1 = a[1] + a[2] + a[3];
    int sum2 = a[4] + a[5] + a[6];
    int sum3 = a[7] + a[8] + a[9];
    int sum4 = a[1] + a[4] + a[7];
    int sum5 = a[2] + a[5] + a[8];
    int sum6 = a[3] + a[6] + a[9];
    int sum7 = a[1] + a[5] + a[9];
    int sum8 = a[3] + a[5] + a[7];
    if (sum1==15&&sum2==15&&sum3==15&&sum4==15&&sum5==15&&sum6==15&&sum7==15&&sum8==15)
        flag = 1;
}

int main()
{

    while (next_permutation(a + 1, a + 10))
    {
        flag = 0;
        condition();
        if (flag)
        {
            cout << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
            cout << a[4] << ' ' << a[5] << ' ' << a[6] << endl;
            cout << a[7] << ' ' << a[8] << ' ' << a[9] << endl;
            cout << endl;
        }
    }
}
