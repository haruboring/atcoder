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
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    sort(all(H)), reverse(all(H));
    rep(i, min(K, N)) H[i] = 0;

    int cnt = 0;
    rep(i, N) cnt += H[i];

    cout << cnt << endl;
}
