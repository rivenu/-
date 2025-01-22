#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, m;

int main()
{
    int n, m;
    double pos, total;
    cin >> n>> m;
    for (int i = 0; i < n; i++)
    {
        pos = (double)i / n * (n + m);     // 计算每个点的原横坐标
        total += fabs((int)(pos + 0.5) - pos); // 取p的小数部分进行累加，得总移动距离,小数部分=移动距离=新横坐标-原横坐标
    }
    total = (double)total / (m + n) * 10000; // 把总移动距离按比例换算成弧长
    printf("%.4f\n", total);
}
