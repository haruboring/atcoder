#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

// 区間加算・区間最小値取得
int op(int a, int b) { return min(a, b); }
int e() { return 1e18; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N) rep(j, M) cin >> A[i][j];

    vector<int> Al(0);
    rep(i, N) rep(j, M) Al.push_back(A[i][j]);
    sort(all(Al));
    map<int, int> mp;
    rep(i, N * M) mp[Al[i]] = i;
    vector<int> tmp_o(N * M);
    rep(i, N * M) tmp_o[i] = i;
    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> o(tmp_o);

    int ans = 0;
    set<int> s;
    rep(i, N) rep(j, M) s.insert(A[i][j]);
    rep(i, N) {
        int tmp = M * (M + 1) / 2;
        tmp *= (N - i - 1);

        rep(j, M) {
            int idx = mp[A[i][j]];
            tmp += o.get(idx) - j;
        }

        ans += tmp;

        rep(j, M) {
            int idx = mp[A[i][j]];
            o.apply(idx, N * M, -1);
        }
    }

    cout << ans << endl;
}
