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
    vector<int> l(N), r(N);
    rep(i, N) cin >> l[i] >> r[i];

    map<int, vector<int>> inserts, erases;
    rep(i, N) inserts[l[i]].push_back(i), erases[r[i]].push_back(i);

    vector<int> vs;
    rep(i, N) vs.push_back(l[i]), vs.push_back(r[i]);
    sort(all(vs));
    vs.erase(unique(all(vs)), vs.end());

    int ans = 0;
    int cnt = 0;
    for (int v : vs) {
        int insert_cnt = inserts[v].size();
        ans += cnt * insert_cnt + insert_cnt * (insert_cnt - 1) / 2;
        cnt += insert_cnt;
        cnt -= erases[v].size();
    }

    cout << ans << endl;
}
