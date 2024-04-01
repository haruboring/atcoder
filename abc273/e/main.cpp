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

    vector<string> flags(Q);
    vector<int> xs(Q, -1);
    rep(i, Q) {
        cin >> flags[i];
        if (flags[i] != "DELETE") {
            cin >> xs[i];
        }
    }
    vector<pair<int, int>> v(1000000, {-1, -1});
    map<int, int> check_point;
    set<int> undecideds;
    int now = 0;
    repp(i, 1, 1000000) {
        undecideds.insert(i);
    }
    rep(i, Q) {
        if (flags[i] == "ADD") {
            int idx = *undecideds.begin();
            undecideds.erase(undecideds.begin());
            v[idx] = {xs[i], now};
            now = idx;

            cout << v[idx].first << endl;
        } else if (flags[i] == "DELETE") {
            int idx = v[now].second;
            now = idx;

            if (now == -1) {
                now = 0;
                cout << -1 << endl;
            } else {
                cout << v[now].first << endl;
            }
        } else if (flags[i] == "SAVE") {
            check_point[xs[i]] = now;

            cout << v[now].first << endl;
        } else if (flags[i] == "LOAD") {
            now = check_point[xs[i]];

            cout << v[now].first << endl;
        }
    }
}
