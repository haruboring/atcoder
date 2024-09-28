// #include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int get_score(vector<tuple<int, int, int, int>> ans, int L) {
    int N = 1000;  // N=1000
    int C = 0;
    for (auto [x, y, x_new, y_new] : ans) {
        C += (x_new - x) + (y_new - y);
    }
    int score = round(1e6 * (1.0 + (double)C / (N * L)));
    return score;
}

signed main() {
    int N;
    cin >> N;  // N=1000
    vector<pair<int, int>> AB(N);
    rep(i, N) cin >> AB[i].first >> AB[i].second;

    multiset<int> As, Bs;
    rep(i, N) {
        As.insert(AB[i].first);
        Bs.insert(AB[i].second);
    }

    set<pair<int, int>> ABs;
    rep(i, N) ABs.insert(AB[i]);

    cout << N << endl;
    vector<tuple<int, int, int, int>> ans;
    rep(i, N) {
        cout << "0 0 " << AB[i].first << " " << AB[i].second << endl;
        ans.push_back({0, 0, AB[i].first, AB[i].second});
    }

    // int L = -1;
    // rep(i, N) L = max({L, AB[i].first, AB[i].second});  // 1003667
    // cout << get_score(ans, L) << endl;
}