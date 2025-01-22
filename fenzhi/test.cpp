#include <iostream>
using namespace std;

int a[10000][10000];
int n, k;
const int MOD = 1e9 + 7; // 定义模数

void multiplyMatrices2();
void output();
void Init();

// 对矩阵中的每个元素进行取模操作
void mod();

int main()
{
    Init();
    mod(); // 在k次乘法之前进行取模操作
    for (int i = 0; i < k - 1; i++)
    {
        multiplyMatrices2();
    }
    output();
    return 0;
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Init()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void mod()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] %= MOD;
        }
    }
}

void multiplyMatrices2()
{
    int **result = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        result[i] = new int[n]{0};
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                result[i][j] = (result[i][j] + a[i][k] * a[k][j]) % MOD;
            }
        }
    }
    for (int i= 0; i < n; i++)
        for (int j= 0; j < n; j++)
            a[i][j] = result[i][j];
            delete[] result;
}
