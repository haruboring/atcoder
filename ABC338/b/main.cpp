#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    map<char, int> mp;
    rep(i, S.size()) mp[S[i]]--;

    vector<pair<int, char>> vv;
    for (auto [k, v] : mp) {
        vv.push_back(make_pair(v, k));
    }
    sort(all(vv));

    cout << vv[0].second << endl;
}
