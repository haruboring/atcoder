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
    vector<int> A(N + 1);
    rep(i, N) cin >> A[i + 1];

    map<int, int> mp;
    rep(i, N) mp[A[i + 1]] = i + 1;

    vector<pair<int, int>> ans;
    repp(i, 1, N + 1) {
        if (A[i] == i) continue;
        int j = mp[i];
        ans.push_back({i, j});
        swap(A[i], A[j]);
        swap(mp[i], mp[A[j]]);
    }

    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}
