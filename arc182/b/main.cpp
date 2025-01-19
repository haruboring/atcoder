#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;

    rep(_, T) {
        int N, K;
        cin >> N >> K;

        if (N >= pow(2, K - 1)) {
            rep(i, N) cout << max((int)pow(2, K) - 1 - i, 1LL) << " ";
            cout << endl;
        } else {
            repp(j, 1, N + 1) {
                bitset<32> bs(j);
                int a = 1;
                rep(i, K - 1) {
                    a *= 2;
                    if (bs[i]) a += 1;
                }
                cout << a << " ";
            }
            cout << endl;
        }
    }
}
