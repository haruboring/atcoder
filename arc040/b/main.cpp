#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, R;
    cin >> N >> R;
    string S;
    cin >> S;

    int l = -1;
    rep(i, N) if (S[i] == '.') l = i;
    if (l == -1) {
        cout << 0 << endl;
        return 0;
    }
    l -= R - 1;
    l = max(0LL, l);

    int ans = 0;
    debug(l);
    rep(i, N) {
        if (i == l) {
            ans++;
            break;
        }
        if (S[i] == '.') {
            ans++;
            repp(j, i, min(N, i + R)) {
                S[j] = 'o';
            }
        }
        ans++;
    }

    cout << ans << endl;
}
