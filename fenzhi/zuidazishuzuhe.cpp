#include <iostream>
using namespace std;
int n, a[1001];
int maxm[1001];

int func()
{
    int pre = 0, result = a[0];
    for (int i = 0; i < n; i++)
    {
        pre = max(pre + a[i], a[i]);
        result = max(result, pre);
    }
    return result;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    maxm[n - 1] = a[n - 1]; // 初始化maxm
    int res = func();
    cout<<res;
    return 0;
}
