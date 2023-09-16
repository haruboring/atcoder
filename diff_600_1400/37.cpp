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

    deque<pair<string, int>> q;
    q.push_back(make_pair("a", 0));
    rep(i, N - 1) {
        int size = q.size();
        rep(k, size) {
            auto [s, ma] = q.front();
            rep(j, ma + 2) {
                q.push_back(make_pair(s + (char)('a' + j), max(ma, j)));
            }
            q.pop_front();
        }
    }

    while (!q.empty()) {
        auto [s, ma] = q.front();
        cout << s << endl;
        q.pop_front();
    }
}