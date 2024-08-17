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
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<int, set<int>> mp;
    int tmp = 0;
    mp[0].insert(0);
    rep(i, N - 1) {
        tmp += A[i];
        mp[tmp % M].insert(i + 1);
    }

    int ans = 0;
    rep(i, M) {
        int size = mp[i].size();
        ans += size * (size - 1) / 2;
    }

    debug(ans);

    int all = accumulate(all(A), 0LL);
    debug(all);

    vector<int> B(N);
    rep(i, N - 1) B[i + 1] = B[i] + A[i];
    int idx = 0;

    if (all % M == 0) ans -= N;
    for (auto a : B) {
        int Mm = (all % M + a) % M;
        ans += mp[Mm].size();
        mp[a % M].erase(idx);
        idx++;
    }

    cout << ans << endl;
}
