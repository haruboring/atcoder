#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int L, R;
    cin >> L >> R;

    vector<pair<int, int>> p;
    int l = L, r = R;
    while (l < r) {
        for (int i = 60; i >= 0; i--) {
            int ti = pow(2, i);
            if (l % ti != 0) continue;
            int j = l / ti;

            if (ti * (j + 1) > r) continue;
            p.push_back({l, ti * (j + 1)});
            l = ti * (j + 1);

            break;
        }
    }

    sort(all(p));
    cout << p.size() << endl;
    for (auto [l, r] : p) {
        cout << l << " " << r << endl;
    }
}
