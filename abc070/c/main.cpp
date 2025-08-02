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
    vector<int> T(N);
    rep(i, N) cin >> T[i];

    if (N == 1) {
        cout << T[0] << endl;
        return 0;
    }
    int cnt = lcm(T[0], T[1]);
    rep(i, N - 2) cnt = lcm(cnt, T[i + 2]);
    cout << cnt << endl;
}