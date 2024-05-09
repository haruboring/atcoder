// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200000 + 100);

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
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> u(M), v(M), w(M);
    rep(i, M) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> edge(0);
    rep(i, M) {
        mp[{u[i], v[i]}] = w[i];
        mp[{v[i], u[i]}] = w[i];
        edge.push_back({u[i], v[i]});
    }

    int ans = 1e18;
    int size = edge.size();

    foreach_comb(size, N - 1, [&](int *indexes) {
        init(N);
        int sum = 0;
        rep(j, N - 1) {
            sum += mp[{edge[indexes[j]].first, edge[indexes[j]].second}];
            unite(edge[indexes[j]].first, edge[indexes[j]].second);
        }
        set<int> st2;
        rep(j, N) st2.insert(root(j));
        if (st2.size() == 1) ans = min(ans, sum % K);
    });

    cout << ans << endl;
}
