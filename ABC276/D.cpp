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
    vector<int> a(N), ac(N);
    map<int, pair<int, int>> waru;
    rep(i, N) {
        cin >> a[i];
        ac[i] = a[i];
    }
    ll cnt = 0;
    sort(all(ac));
    rep(i, N) {
        while (1) {
            if (a[i] % 2 != 0) {
                break;
            }
            a[i] /= 2;
            cnt++;
            waru[i].first++;
        }
        while (1) {
            if (a[i] % 3 != 0) {
                break;
            }
            a[i] /= 3;
            cnt++;
            waru[i].second++;
        }
    }
    rep(i, N - 1) {
        if (a[i] != a[i + 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int m2 = 100000, m3 = 100000;
    rep(i, N) {
        m2 = min(m2, waru[i].first);
        m3 = min(m3, waru[i].second);
    }
    cout << cnt - N * (m2 + m3) << endl;
}