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

    set<int> d3, d4;
    rep(i, N - 2) {
        if (P[i] < P[i + 1] && P[i + 1] > P[i + 2]) d3.insert(i);
        if (P[i] > P[i + 1] && P[i + 1] < P[i + 2]) d4.insert(i);
    }

    d4.insert(1e8), d3.insert(1e8);
    d4.insert(1e9), d3.insert(1e9);

    int cnt = 0;
    rep(i, N - 1) {
        int d3f = *d3.begin();
        d3.erase(d3f);
        int d3s = *d3.begin();
        d3.erase(d3s);

        int d4f = *d4.begin();
        d4.erase(d4f);
        int d4s = *d4.begin();
        d4.erase(d4s);

        int df = max(d3f, d4f) + 2;
        int ds = min(d3s, d4s) + 1;
        if (P[i] < P[i + 1] && df < 1e8) cnt += max(0LL, min(N - 1, ds) - df + 1);

        d3.insert(d3f), d3.insert(d3s);
        d4.insert(d4f), d4.insert(d4s);

        if (d3.count(i)) d3.erase(i);
        if (d4.count(i)) d4.erase(i);
    }

    cout << cnt << endl;
}
