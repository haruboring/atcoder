#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H) rep(j, W) cin >> B[i][j];

    vector<int> orders_i, orders_j;
    rep(i, H) orders_i.push_back(i);
    rep(j, W) orders_j.push_back(j);

    int ans = 1e18;
    do {
        do {
            vector<vector<int>> C(H, vector<int>(W));
            rep(i, H) rep(j, W) C[i][j] = A[orders_i[i]][orders_j[j]];

            bool ok = true;
            rep(i, H) rep(j, W) if (C[i][j] != B[i][j]) ok = false;
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        } while (next_permutation(all(orders_j)));
    } while (next_permutation(all(orders_i)));

    if (ans == 1e18) ans = -1;
    cout << ans << endl;
}
