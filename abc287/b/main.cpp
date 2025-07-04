#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    int cnt = 0;
    rep(i, N) {
        rep(j, M) {
            if (S[i].substr(3, 3) == T[j]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
}
