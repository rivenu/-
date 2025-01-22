#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 50;

struct Node {
    double w, d;
} a[maxn];

double s, v, p, dp[maxn];
int n, pre[maxn], t[maxn];

double min(double x, double y) {
    if (x <= y) return x;
    return y;
}

int main() {
    int i, j;
    cin >> s >> v >> p >> dp[0] >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i].d >> a[i].w, dp[i] = 1e9;
    double road = v * p;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= i - 1; j++) {
            if (a[i].d - a[j].d > road || (a[i].d - a[j].d) * 2 < road) continue;
            double ned = (a[i].d - a[j].d) / p;
            if (dp[i] > dp[j] + ned * a[i].w + 2) {
                dp[i] = dp[j] + ned * a[i].w + 2;
                pre[i] = j;
            }
        }
    }
    double ans = 0x3f3f3f3f;
    int last = 0, tot = 0;
    for (i = 0; i <= n; i++) {
        if (road < s - a[i].d) continue;
        if (ans > dp[i]) {
            ans = dp[i];
            last = i;
        }
    }
    while (last != 0) {
        t[++tot] = last;
        last = pre[last];
    }
    printf("%.2lf %d\n", ans, tot);
    for (i = tot; i >= 1; i--)
        cout << t[i] << ' ';
    cout << endl;
    return 0;
}
