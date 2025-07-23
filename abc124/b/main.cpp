#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    int cnt = 0, ma = -1;
    rep(i, N) {
        if (H[i] >= ma) cnt++;
        ma = max(ma, H[i]);
    }

    cout << cnt << endl;
}
