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
    set<string> s;
    bool ans = true;
    rep(i, N) {
        cin >> S[i];
        if (s.count(S[i])) {
            ans = false;
        }
        s.insert(S[i]);
    }
    rep(i, N) {
        if (!(S[i][0] == 'H' || S[i][0] == 'D' || S[i][0] == 'C' || S[i][0] == 'S')) {
            ans = false;
        }
        if (!(S[i][1] == 'A' || S[i][1] == '2' || S[i][1] == '3' || S[i][1] == '4' || S[i][1] == '5' || S[i][1] == '6' || S[i][1] == '7' || S[i][1] == '8' || S[i][1] == '9' || S[i][1] == 'T' || S[i][1] == 'J' || S[i][1] == 'Q' || S[i][1] == 'K')) {
            ans = false;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}