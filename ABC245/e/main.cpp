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
    vector<int> A(N), B(N), C(M), D(M);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, M) cin >> C[i];
    rep(i, M) cin >> D[i];

    vector<tuple<int, int, int>> chbo(N + M);
    rep(i, N) chbo[i] = {A[i], B[i], 0};
    rep(i, M) chbo[i + N] = {C[i], D[i], 1};
    sort(all(chbo));
    reverse(all(chbo));
    multiset<int> s;

    rep(i, N + M) {
        int a, b, c;
        tie(a, b, c) = chbo[i];
        if (c == 1) {
            s.insert(b);
        } else {
            auto it = s.lower_bound(b);
            if (it == s.end()) {
                cout << "No" << endl;
                return 0;
            }
            s.erase(it);
        }
    }

    cout << "Yes" << endl;
}
