#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(500'000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, M) A[i]--, B[i]--;

    int cnt = M;
    vector<vector<int>> G(N, vector<int>(0)), nG(N, vector<int>(0));
    init(N);
    rep(i, M) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    vector<pair<int, int>> v(N);
    rep(i, N) v[i] = {G[i].size(), i};
    sort(all(v));

    rep(i, N) {
        auto [xx, vv] = v[i];
        if (xx > 2) continue;
        for (auto nv : G[vv]) {
            if (G[nv].size() >2) continue;
            nG[vv].push_back(nv);
            nG[nv].push_back(vv);
            cnt--;
        }
    }

    debug(cnt);

    rep(v, N) {
        for (auto nv : nG[v]) {
            unite(v, nv);
        }
    }

    set<int> lack, s;
    rep(i, N) {
        s.insert(root(i));
        if (nG[i].size() < 2) lack.insert(root(i));
    }

    cnt += lack.size();
    cout << cnt << endl;
}