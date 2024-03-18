#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

using mint = atcoder::modint998244353;
mint a_score = 0, b_score = 0;
vector<vector<double>> un(1000000 + 100, vector<double>(2, false));

void dfs(double is_a, int point, int N, mint p) {
    if (point == N) return;

    if (un[point][is_a]) return;

    un[point][is_a] = true;

    if (is_a) {
        a_score += p * mint(point) * (mint(N - point).inv());
    } else {
        b_score += p * mint(point) * (mint(N - point).inv());
    }
    dfs(!is_a, point + 1, N, p * (mint(1) - mint(point) * (mint(N - point).inv())));

    cout << point << ", " << a_score.val() << " " << b_score.val() << endl;
    dfs(!is_a, point, N, p * mint(point) * (mint(N).inv()));
}

signed main() {
    int N;
    cin >> N;

    dfs(true, 0, N, mint(1));

    cout << a_score.val() << " " << b_score.val() << endl;
}
