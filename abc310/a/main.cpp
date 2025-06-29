#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> D(N);
    rep(i, N) cin >> D[i];

    sort(all(D));

    if (P > Q + D[0]) {
        cout << Q + D[0] << endl;
    } else {
        cout << P << endl;
    }
}
