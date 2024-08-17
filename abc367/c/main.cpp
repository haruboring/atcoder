#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> R(N);
    rep(i, N) cin >> R[i];

    if (N == 1) {
        repp(i, 1, R[0] + 1) {
            if (i % K != 0) continue;
            cout << i << endl;
        }
        return 0;
    }

    queue<vector<int>> preq;
    repp(i, 1, R[0] + 1) preq.push({i});

    repp(i, 1, N) {
        queue<vector<int>> q;
        while (!preq.empty()) {
            vector<int> v = preq.front();
            preq.pop();
            repp(j, 1, R[i] + 1) {
                vector<int> nv = v;
                nv.push_back(j);
                q.push(nv);
            }
        }
        preq = q;
    }

    vector<vector<int>> a(0, vector<int>(N));
    while (!preq.empty()) {
        a.push_back(preq.front());
        preq.pop();
    }

    vector<vector<int>> b(0, vector<int>(N));
    rep(i, a.size()) {
        int sum = accumulate(all(a[i]), 0LL);
        if (sum % K == 0) {
            b.push_back(a[i]);
        }
    }

    sort(all(b));
    rep(i, b.size()) {
        rep(j, b[i].size()) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
