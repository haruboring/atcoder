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
    vector<vector<int>> G(N, vector<int>(0));
    int root = -1;
    rep(i, N) {
        int A;
        cin >> A;
        A--;
        if (A == -2) {
            root = i;
            continue;
        }
        G[A].push_back(i);
    }

    queue<int> q;
    q.push(root);
    cout << root + 1 << " ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto nv : G[v]) {
            cout << nv + 1 << " ";
            q.push(nv);
        }
    }

    cout << endl;
}
