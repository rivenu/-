#include <iostream>
using namespace std;
long long cnt = 0;
int n;
int a[1000], b[1000];

void mergesort(int start, int end);
void merge(int start, int mid, int end);

int main()
{
    int ul;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> ul;
    if (ul == 0)
        mergesort(0, n - 1);
    cout << cnt;
}

void mergesort(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergesort(start, mid);
        mergesort(mid + 1, end);
        merge(start, mid, end);
    }
}

void merge(int start, int mid, int end)
{
    int p1 = start, p2 = mid+1, bindex = 0;
    while (p1 <= mid && p2 <= end)
    {
        if (a[p1] <= a[p2]) // 直接放入则不需要交换
            b[bindex++] = a[p1++];
        else
        { // 交换则加上操作数
            b[bindex++] = a[p2++];
            cnt += mid - p1 + 1;
        }
    }
    while (p1 <= mid)
        b[bindex++] = a[p1++];
    while (p2 <= end)
        b[bindex++] = a[p2++];

    for (int i = 0; i <= end - start; i++)
        a[start + i] = b[i];
}