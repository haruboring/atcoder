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
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i];
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    rep(i, N - 1) A[i]--, B[i]--;
    sort(all(C));

    vector<set<int>> G(N);
    rep(i, N - 1) {
        G[A[i]].insert(B[i]);
        G[B[i]].insert(A[i]);
    }
    set<pair<int, int>> s;
    rep(i, N) s.insert({G[i].size(), i});

    vector<int> ans(N);
    int i = 0;
    while (!s.empty()) {
        auto [_, v] = *s.begin();
        s.erase(s.begin());

        ans[v] = C[i];
        i++;

        for (int u : G[v]) {
            s.erase({G[u].size(), u});
            G[u].erase(v);
            s.insert({G[u].size(), u});
        }
    }

    int sum = 0;
    rep(i, N - 1) sum += min(ans[A[i]], ans[B[i]]);

    cout << sum << endl;
    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}
