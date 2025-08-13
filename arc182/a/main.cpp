#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(Q), V(Q);
    rep(i, Q) cin >> P[i] >> V[i];

    vector<int> s(Q);
    rep(i, Q - 1) {
        repp(j, i + 1, Q) {
            if (V[i] <= V[j]) {
                continue;
            } else if (P[i] == P[j]) {
                cout << 0 << endl;
                return 0;
            } else if (P[i] < P[j]) {
                if ((s[i] != 0 && s[i] != 1) || (s[j] != 0 && s[j] != -1)) {
                    cout << 0 << endl;
                    return 0;
                }
                s[i] = 1;
                s[j] = -1;
            } else {
                if ((s[i] != 0 && s[i] != -1) || (s[j] != 0 && s[j] != 1)) {
                    cout << 0 << endl;
                    return 0;
                }
                s[i] = -1;
                s[j] = 1;
            }
        }
    }
    int x = 0;
    rep(i, Q) if (s[i] == 0) x++;
    mint ans = 2;
    ans = ans.pow(x);

    cout << ans.val() << endl;
}
