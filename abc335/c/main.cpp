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

    vector<pair<int, int>> pos(N);
    rep(i, N) pos[i] = {N - i, 0};

    map<char, pair<int, int>> move = {
        {'L', {-1, 0}},
        {'R', {1, 0}},
        {'U', {0, 1}},
        {'D', {0, -1}}};

    int cnt = 0;
    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            char c;
            cin >> c;

            pos.push_back({pos.back().first + move[c].first, pos.back().second + move[c].second});
            cnt++;
        } else {
            int p;
            cin >> p;

            int idx = N - p + cnt;
            cout << pos[idx].first << " " << pos[idx].second << endl;
        }
    }
}
