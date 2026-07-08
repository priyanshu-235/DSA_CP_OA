#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
// just check here some values were according to question.
struct Matrix {
    vector<vector<ll>> a;
};

Matrix multiply(Matrix A, Matrix B, int n) {
    Matrix C;
    C.a.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            if (A.a[i][k])
                for (int j = 0; j < n; j++)
                    C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
    return C;
}

Matrix MatPow(Matrix D, ll exp, int n) {
    Matrix K;
    K.a.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) K.a[i][i] = 1;
    while (exp > 0) {
        if (exp & 1) K = multiply(K, D, n);
        D = multiply(D, D, n);
        exp >>= 1;
    }
    return K;
}
