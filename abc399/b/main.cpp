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
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    map<int, int> m;
    rep(i, N) m[-P[i]]++;

    int t = 1;
    for (auto [k, v] : m) {
        m[k] = t;
        t += v;
    }

    rep(i, N) cout << m[-P[i]] << " ";
    cout << endl;
}
