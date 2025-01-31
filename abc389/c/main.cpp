#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;
    int mi = 0;

    vector<pair<int, int>> V;
    int e_cnt = 0;
    rep(i, Q) {
        int t, x;
        cin >> t;
        if (t == 1) {
            cin >> x;
            if (e_cnt == V.size()) {
                V.push_back({0, x});
            } else {
                V.push_back({V[V.size() - 1].first + V[V.size() - 1].second, x});
            }
        } else if (t == 2) {
            mi += V[e_cnt].second;
            e_cnt++;
        } else {
            cin >> x;
            cout << V[x - 1 + e_cnt].first - mi << endl;
        }
    }
}
