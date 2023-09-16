#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    int R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;

    ll ans = 0;
    rep(i, N) {
        if (i + K < N) {
            if (T[i] == T[i + K]) {
                T[i + K] = 'x';
            }
        }
        if (T[i] == 'r') ans += P;
        if (T[i] == 's') ans += R;
        if (T[i] == 'p') ans += S;
    }

    cout << ans << endl;
}