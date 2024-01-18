#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    rep(i, T) cin >> a[i];

    vector<pair<int, int>> v;
    rep(i, T) v.push_back({a[i], i});

    int ans = 0;

    int pre_cake = -1;
    rep(_, K) {
        sort(all(v));
        reverse(all(v));

        rep(i, T + 1) {
            if (v[i].first <= 0 || i == T) {
                v[0].first--;
                pre_cake = v[0].second;
                ans++;
                break;
            }
            if (v[i].second == pre_cake) continue;
            v[i].first--;
            pre_cake = v[i].second;
            break;
        }
    }

    cout << ans << endl;
}