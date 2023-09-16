#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, D;
    cin >> N >> D;
    vector<int> T(N);
    rep(i, N) {
        cin >> T[i];
    }
    rep(i, N - 1) {
        if (T[i + 1] - T[i] <= D) {
            cout << T[i + 1] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}