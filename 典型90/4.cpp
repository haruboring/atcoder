#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    vector<int> row_sum(H), col_sum(W);
    rep(i, H) rep(j, W) {
        row_sum[i] += A[i][j];
        col_sum[j] += A[i][j];
    }

    rep(i, H) {
        rep(j, W) {
            cout << row_sum[i] + col_sum[j] - A[i][j] << " ";
        }
        cout << endl;
    }
}