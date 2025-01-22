#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7; // 定义模数

int n, k;
int** multiplyMatrices(int** mat1, int** mat2);
int** matrixPower(int** matrix, int power);

int main() {
    cin >> n >> k;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            matrix[i][j] %= MOD; // 输入后立即取模
        }
    }

    // 计算矩阵的幂
    int** result = matrixPower(matrix, k);

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        delete[] result[i];
    }
    delete[] matrix;
    delete[] result;

    return 0;
}

// 矩阵乘法函数
int** multiplyMatrices(int** mat1, int** mat2) {
    int** result = new int*[n];
    for (int i = 0; i < n; ++i) {
        result[i] = new int[n]{0};
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] = (result[i][j] + mat1[i][k] * mat2[k][j]) % MOD;
            }
        }
    }
    return result;
}

// 矩阵幂函数
int** matrixPower(int** matrix, int power) {
    int** result = new int*[n];
    for (int i = 0; i < n; ++i) {
        result[i] = new int[n]{0};
        result[i][i] = 1; // 初始化结果矩阵为单位矩阵
    }

    int** base = matrix;
    while (power > 0) {
        if (power % 2 == 1) {
            result = multiplyMatrices(result, base);
        }
        base = multiplyMatrices(base, base);
        power /= 2;
    }

    return result;
}