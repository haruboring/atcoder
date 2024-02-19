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
    set<string> set_S;
    vector<pair<int, int>> Ti(0);
    rep(i, N) {
        int T;
        string S;
        cin >> S >> T;
        if (set_S.count(S) == false) {
            set_S.insert(S);
            Ti.push_back(make_pair(-T, i + 1));
        }
    }
    sort(all(Ti));
    cout << Ti[0].second << endl;
}