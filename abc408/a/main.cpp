#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, S;
    cin >> N >> S;
    vector<int> T(N + 1);
    rep(i, N) cin >> T[i + 1];

    rep(i, N) {
        if (T[i + 1] - T[i] > S) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
