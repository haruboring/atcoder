#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Y;
    cin >> N >> Y;
    rep(i, N + 1) {
        repp(j, i, N + 1) {
            if (i * 10000 + (j - i) * 5000 + (N - j) * 1000 == Y) {
                cout << i << " " << (j - i) << " " << N - j << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}