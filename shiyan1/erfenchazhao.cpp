#include <iostream>
using namespace std;
int n, m;
int a[10000], b[10000], exist[50000];
int bcnt = 0;

void find(int left, int right);
void output(int i);

int main()
{   
    for(int i = 0;i<50000;i++)exist[i]=0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
    {
        find(0, n - 1);
        bcnt++;
        output(i);
    }
}

void find(int left, int right)
{
    if (a[left] == b[bcnt] || a[right] == b[bcnt])
    {
        exist[bcnt] = 1;
        return;
    }
    if(left==right)return;
    if (left < right)
    {
        int mid = (left + right) / 2;
        if (b[bcnt] <= a[mid])
            find(left, mid);
        else
            find(mid + 1, right);
    }
}

void output(int i)
{
    if (exist[i])
        cout << "Yes\n";
    else
        cout << "No\n";
}