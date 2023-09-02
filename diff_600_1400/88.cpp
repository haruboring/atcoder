#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    vector<vector<int>> G(N);
    rep(i, M) {
        G[B[i] - 1].push_back(A[i] - 1);
        G[A[i] - 1].push_back(B[i] - 1);
    }

    vector<int> ans(N, -1);
    queue<int> q;
    q.push(0);
    ans[0] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int nv : G[v]) {
            if (ans[nv] != -1) continue;
            ans[nv] = v;
            q.push(nv);
        }
    }

    rep(i, N) {
        if (ans[i] == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    repp(i, 1, N) {
        cout << ans[i] + 1 << endl;
    }
}
