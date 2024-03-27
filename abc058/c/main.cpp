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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<multiset<char>> v(N);
    rep(i, N) {
        for (char c : S[i]) {
            v[i].insert(c);
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        int min_count = 1e9;
        rep(i, N) {
            int count = v[i].count(c);
            min_count = min(min_count, count);
        }
        rep(i, min_count) {
            cout << c;
        }
    }
    cout << endl;
}
