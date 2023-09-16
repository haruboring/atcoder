#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> Z(H + 2, vector<int>(W + 2));
    rep(i, N) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        Z[A][B]++;
        Z[A][D + 1]--;
        Z[C + 1][B]--;
        Z[C + 1][D + 1]++;
    }
    rep(i, H + 1) {
        int cnt = 0;
        rep(j, W + 1) {
            cnt += Z[i][j];
            Z[i][j] = cnt;
        }
    }
    rep(i, W + 1) {
        int cnt = 0;
        rep(j, H + 1) {
            cnt += Z[j][i];
            Z[j][i] = cnt;
        }
    }
    rep(i, H) {
        rep(j, W) {
            cout << Z[i + 1][j + 1] << " ";
        }
        cout << endl;
    }
}