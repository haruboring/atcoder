#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int S, T;
    cin >> S >> T;

    int cnt = 0;
    rep(i, S + 1) {
        rep(j, S + 1) {
            rep(k, S + 1) {
                if (i + j + k > S) continue;
                if (i * j * k > T) continue;

                cnt++;
            }
        }
    }

    cout << cnt << endl;
}