#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200'000 + 100);

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
    vector<int> K(M), C(M);
    vector<vector<int>> A(M);
    rep(i, M) {
        cin >> K[i] >> C[i];
        rep(j, K[i]) {
            int a;
            cin >> a;
            A[i].push_back(a - 1);
        }
    }

    vector<pair<int, vector<int>>> edges;
    rep(i, M) {
        edges.push_back({C[i], A[i]});
    }

    sort(all(edges));

    init(N);

    int ans = 0;
    for (auto [c, a] : edges) {
        set<int> un;
        for (auto x : a) {
            if (root(x) == root(a[0])) {
                continue;
            }
            unite(x, a[0]);
            ans += c;
        }
    }

    set<int> st;
    rep(i, N) {
        st.insert(root(i));
    }

    if (st.size() == 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
