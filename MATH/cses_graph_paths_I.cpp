#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

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

int main(){
    int n, m; ll k;
    cin >> n >> m >> k;
    Matrix Adj;
    Adj.a.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        Adj.a[u-1][v-1]++;  // handles multi-edges
    }
    Matrix A_K = MatPow(Adj, k, n);
    cout << A_K.a[0][n-1] << endl; // because in s_0 only first position is 1 => because only number of path to 0 with edges 0 is 1 that is start.
    
}