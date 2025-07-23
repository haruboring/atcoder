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
    vector<int> D(N);
    rep(i, N) cin >> D[i];

    int cnt = 0;
    rep(i, N) {
        rep(j, D[i]) {
            string s = to_string(i + 1) + to_string(j + 1);
            sort(all(s));
            if (s[0] == s[s.size() - 1]) cnt++;
        }
    }

    cout << cnt << endl;
}
