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
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    // rep(i, M) A[i]--, B[i]--;

    map<int, int> m;
    rep(i, M) m[(A[i] + B[i]) % N]++;

    int cnt = 0;
    // debug(cnt);
    for (auto [k, v] : m) {
        // debug(v);
        // debug(M - v);
        cnt += v * (M - v);
        M -= v;
        // debug(cnt);
    }
    cout << cnt << endl;
}
