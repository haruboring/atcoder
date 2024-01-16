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
        string s = to_string(i + 1);
        set<char> st;
        rep(j, s.size()) st.insert(s[j]);
        if (st.size() != 1) continue;
        string t = ""s + *st.begin();
        rep(j, 10) {
            if (stoll(t) <= D[i]) {
                cnt++;
            }
            t += *st.begin();
        }
    }

    cout << cnt << endl;
}