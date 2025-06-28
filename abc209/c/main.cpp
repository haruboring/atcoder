#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint1000000007;

signed main() {
    int N;
    cin >> N;
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    sort(all(C));

    mint cnt = 1;
    rep(i, N) {
        if (C[i] - i <= 0) {
            cout << 0 << endl;
            return 0;
        }
        cnt *= C[i] - i;
    }
    cout << cnt.val() << endl;
}
