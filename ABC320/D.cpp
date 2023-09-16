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
    vector<int> A(M), B(M), X(M), Y(M);
    rep(i, M) {
        cin >> A[i] >> B[i] >> X[i] >> Y[i];
        A[i]--;
        B[i]--;
    }

    vector<vector<int>> G(N, vector<int>(0));
    map<pair<int, int>, pair<int, int>> mp;
    rep(i, M) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
        mp[make_pair(A[i], B[i])] = make_pair(X[i], Y[i]);
        mp[make_pair(B[i], A[i])] = make_pair(-X[i], -Y[i]);
    }

    vector<int> ansX(N), ansY(N);
    rep(i, N) {
        ansX[i] = 1e18;
        ansY[i] = 1e18;
    }

    queue<int> que;
    que.push(0);
    ansX[0] = 0;
    ansY[0] = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nv : G[v]) {
            if (ansX[nv] != 1e18) continue;
            auto [dx, dy] = mp[make_pair(v, nv)];
            ansX[nv] = ansX[v] + dx;
            ansY[nv] = ansY[v] + dy;
            que.push(nv);
        }
    }

    rep(i, N) {
        if (ansX[i] == 1e18 || ansY[i] == 1e18) {
            cout << "undecidable" << endl;
            continue;
        }
        cout << ansX[i] << " " << ansY[i] << endl;
    }
}
