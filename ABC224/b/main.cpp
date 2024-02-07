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
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    bool ans = true;
    rep(i, H - 1) {
        rep(j, W - 1) {
            repp(k, i + 1, H) {
                repp(l, j + 1, W) {
                    if (A[i][j] + A[k][l] > A[i][l] + A[k][j]) {
                        ans = false;
                    }
                }
            }
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}