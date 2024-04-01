#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> x(Q);
    rep(i, Q) cin >> x[i];

    set<int> s;
    vector<int> s_size(Q);
    rep(i, Q) {
        if (s.count(x[i])) {
            s.erase(x[i]);

        } else {
            s.insert(x[i]);
        }
        s_size[i] = s.size();
    }

    s.clear();
    vector<int> ruiseki_s_size(Q + 1);
    rep(i, Q) {
        ruiseki_s_size[i + 1] = ruiseki_s_size[i] + s_size[i];
    }
    map<int, int> add;
    map<int, int> tmp;
    rep(i, Q) {
        if (tmp.count(x[i])) {
            debug(x[i]);
            int idx = tmp[x[i]];
            add[x[i]] += ruiseki_s_size[i] - ruiseki_s_size[idx];
            tmp.erase(x[i]);
        } else {
            tmp[x[i]] = i;
        }
    }
    for (auto [key, value] : tmp) {
        add[key] += ruiseki_s_size[Q] - ruiseki_s_size[tmp[key]];
    }

    rep(i, N) {
        cout << add[i + 1] << endl;
    }
}
