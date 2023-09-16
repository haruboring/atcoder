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
    vector<string> s(N), t(N);
    map<string, int> map;
    rep(i, N) {
        cin >> s[i] >> t[i];
        map[s[i]]++;
        map[t[i]]++;
    }
    rep(i, N) {
        if (map[s[i]] == 2 && s[i] == t[i]) {
            continue;
        }
        if (map[s[i]] != 1) {
            s[i] = "";
        }
        if (map[t[i]] != 1) {
            t[i] = "";
        }
    }
    rep(i, N) {
        if (s[i] == t[i] && s[i] == "") {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}