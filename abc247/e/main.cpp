#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    A.push_back(1e18);

    int cnt = 0;
    multiset<int> x, y;
    int st = 0;
    rep(r, N + 1) {
        if ((A[r] < Y) || (A[r] > X)) {
            repp(l, st, r) {
                if ((x.empty()) || (y.empty())) continue;
                cnt += r - max(*x.begin(), *y.begin());

                if (x.count(l)) x.erase(l);
                if (y.count(l)) y.erase(l);
            }
            x.clear(), y.clear();
            st = 1e18;
        } else {
            st = min(st, r);
            if (A[r] == X) x.insert(r);
            if (A[r] == Y) y.insert(r);
        }
    }

    cout << cnt << endl;
}
