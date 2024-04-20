#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using mint = atcoder::modint998244353;

mint p = 0, q = 0;
int N, A, B, P, Q;
map<tuple<int, int, int>, mint> memo;

mint dfs(pair<int, int> pos, int turn, mint base) {
    auto [a, b] = pos;
    if (a == N) {
        return base;
    }
    if (b == N) {
        return 0;
    }

    if (memo.count({a, b, turn})) {
        return memo[{a, b, turn}];
    }

    mint res = 0;

    if (turn % 2 == 0) {
        // Takahashi
        repp(i, 1, P + 1) {
            if (a + i < N) {
                res += dfs({a + i, b}, turn + 1, base * p);
            }
            if (a + i == N) {
                res += dfs({a + i, b}, turn + 1, base * p * (P + a - N + 1));
            }
        }
    }
    if (turn % 2 == 1) {
        // Aoki
        repp(i, 1, Q + 1) {
            if (b + i <= N) {
                res += dfs({a, b + i}, turn + 1, base * q);
            }
            if (b + i == N) {
                res += dfs({a, b + i}, turn + 1, base * q * (Q + b - N + 1));
            }
        }
    }

    return memo[{a, b, turn}] = res;
}
signed main() {
    cin >> N >> A >> B >> P >> Q;

    p = mint(P).inv();
    q = mint(Q).inv();

    mint ans = dfs({A, B}, 0, mint(1));

    cout << ans.val() << endl;
}
