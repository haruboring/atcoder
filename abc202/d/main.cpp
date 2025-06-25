#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, K;
    cin >> A >> B >> K;

    vector<vector<int>> v(61, vector<int>(61));
    rep(i, 60) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    repp(n, 1, 61) {
        repp(k, 1, 61) {
            v[n][k] = (v[n - 1][k - 1] + v[n - 1][k]);
        }
    }

    int cB = B, o = 0, cA = A;
    debug(v[4][2]);
    rep(i, A + B) {
        // debug(v[(A + B) - i][cB]);
        // debug(K);
        if (v[cA + cB - 1][cB] < K) {
            cout << 'b';
            K -= v[(A + B) - i - 1][cB];
            cB--;
        } else {
            if (cA > 0) {
                cout << 'a';
                cA--;
            } else {
                cout << 'b';
                cB--;
            }
        }
    }
    cout << endl;

    // cout << s << endl;
}
