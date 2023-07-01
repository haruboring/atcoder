#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    rep(i, N) P[i]--;

    map<int, int> mp;
    rep(i, N) {
        mp[P[i]] = i;
    }

    set<int> s;
    rep(i, N - 1) s.insert(i);
    int std = 0;
    int pos = mp[std];
    debug(pos);
    vector<int> ans(0);
    while (!s.empty()) {
        if (std >= N - 1) break;
        while (std < N - 1 && P[std] == std) {
            std++;
            pos = mp[std];
        }
        swap(P[pos - 1], P[pos]);
        swap(mp[P[pos - 1]], mp[P[pos]]);
        ans.push_back(pos - 1);
        if (!s.count(pos - 1)) {
            break;
        }
        s.erase(pos - 1);
        pos--;
    }
    rep(i, N) {
        if (P[i] != i) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (!s.empty()) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, ans.size()) {
        cout << ans[i] + 1 << endl;
    }
}