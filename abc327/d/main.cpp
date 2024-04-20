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
    rep(i, M) cin >> A[i];
    rep(i, M) cin >> B[i];

    vector<vector<int>> G(N, vector<int>(0));

    rep(i, M) {
        G[A[i] - 1].push_back(B[i] - 1);
        G[B[i] - 1].push_back(A[i] - 1);
    }

    vector<bool> visited(N, false);
    vector<bool> even(N, false);

    vector<int> s(2 * M);
    rep(i, M) {
        s[2 * i] = A[i] - 1;
        s[2 * i + 1] = B[i] - 1;
    }

    rep(idx, 2 * M) {
        int i = s[idx];
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        even[i] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int nv : G[v]) {
                if (visited[nv]) {
                    if (even[v] == even[nv]) {
                        cout << "No" << endl;
                        return 0;
                    }
                } else {
                    q.push(nv);
                    visited[nv] = true;
                    even[nv] = !even[v];
                }
            }
        }
    }

    cout << "Yes" << endl;
}