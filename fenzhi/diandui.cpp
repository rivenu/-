#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int t, n;
double cnt = 100000000.0;
struct Point
{
    long long x, y;
};

void cal(Point a, Point b)
{
    double res = sqrt((double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
    if (res < cnt)
        cnt = res;
}

int main()
{

    cin >> t >> n;
    Point points_1[100];
    Point points_2[100];

    for (int i = 0; i < n; i++)
    {
        cin >> points_1[i].x;
        cin >> points_1[i].y;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> points_2[i].x;
        cin >> points_2[i].y;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cal(points_1[i], points_2[j]);
        }
    cout << fixed << setprecision(3);
    cout << cnt << endl;
    return 0;
}