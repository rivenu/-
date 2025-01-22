#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int a[10000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    sort(a, a + n);
    cout << a[m-1];
}