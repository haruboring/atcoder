#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, X;
    cin >> N >> M >> X;
    set<int> s;
    rep(i, M) {
        int A;
        cin >> A;
        s.insert(A);
    }
    int n_cnt = 0;
    repp(i, X, N + 1) {
        if (s.count(i)) {
            n_cnt++;
        }
    }
    int zero_cnt = 0;
    repp(i, 0, X + 1) {
        if (s.count(i)) {
            zero_cnt++;
        }
    }
    cout << min(n_cnt, zero_cnt) << endl;
}