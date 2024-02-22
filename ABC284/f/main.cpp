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
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> vp;
    int cnt = 1;
    int tmp = 1;

    while (tmp <= N) {
        rep(i, N - (tmp - 1)) {
            vp.push_back({i, i + (tmp - 1)});
            mp[{i, i + (tmp - 1)}] = cnt;
            cnt++;
        }
        tmp *= 2;
    }

    cout << vp.size() << endl;
    for (auto [a, b] : vp) {
        cout << a + 1 << " " << b + 1 << endl;
    }
    int Q;
    cin >> Q;
    rep(i, Q) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int size = b - a + 1;
        int tmp = 1;
        while (tmp * 2 <= size) {
            tmp *= 2;
        }
        // if (!mp.count({a, a + (tmp - 1)}) || !mp.count({b - (tmp - 1), b})) {
        //     cout << -1 << " " << -1 << endl;
        //     continue;
        // }
        cout << mp[{a, a + (tmp - 1)}] << " " << mp[{b - (tmp - 1), b}] << endl;
    }
}
