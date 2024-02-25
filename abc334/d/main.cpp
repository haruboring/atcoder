#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> R(N);
    rep(i, N) cin >> R[i];

    sort(all(R));
    vector<int> wa(N);
    wa[0] = R[0];
    repp(i, 1, N) wa[i] = wa[i - 1] + R[i];

    rep(i, Q) {
        int X;
        cin >> X;

        cout << upper_bound(all(wa), X) - wa.begin() << endl;
    }
}
