#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int b;
    int e;
};

bool cmp(node x, node y)
{
    if (x.e == y.e)
    {
        return x.b < y.b;
    }//这个有没有都无所谓，只看结束时间
    return x.e < y.e;
}

int n;
node p[1000];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].b >> p[i].e;
    }
    int now = 1;
    int opt = 2;
    int cnt = 1;
    sort(p+1,p+1+n,cmp);
    while (opt <= n)
    {
        if (p[opt].b >= p[now].e)
        {
            now = opt;
            cnt++;
        }
        opt++;
    }
    cout << cnt << endl;
}
