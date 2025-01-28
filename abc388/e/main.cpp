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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    multiset<int> upper, lower;
    rep(i, N) {
        if (i < N / 2) {
            upper.insert(A[i]);
        } else {
            lower.insert(A[i]);
        }
    }

    int cnt = 0;
    while (lower.size() > 0 && upper.size() > 0) {
        int l = *lower.begin();
        int u = *upper.begin();
        // debug(l);
        // debug(u);
        if (l >= 2 * u) cnt++, upper.erase(upper.find(u));
        lower.erase(lower.find(l));
        // upper.erase(lower.find(u));
    }

    cout << cnt << endl;
}
