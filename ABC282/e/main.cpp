#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int MOD;

int fast_pow(int a, int b, int MOD) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

vector<int> par(250'000 + 100);

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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    MOD = M;
    vector<tuple<int, int, int>> score;
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            int s = (fast_pow(A[i], A[j], M) + fast_pow(A[j], A[i], M)) % MOD;
            score.push_back({s, i, j});
        }
    }

    sort(all(score));
    reverse(all(score));

    init(N * N);
    int ans = 0;
    for (auto [s, a, b] : score) {
        int x = a, y = b;
        if (root(x) == root(y)) continue;
        ans += s;
        unite(x, y);
    }

    cout << ans << endl;
}
