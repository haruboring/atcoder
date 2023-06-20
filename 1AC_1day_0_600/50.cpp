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

    bool a = true;

    rep(i, H - 1) {
        rep(j, W - 1) {
            repp(k, i + 1, H) {
                repp(l, j + 1, W) {
                    if (A[i][j] + A[k][l] > A[i][l] + A[k][j]) {
                        a = false;
                    }
                }
            }
        }
    }
    if (a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}