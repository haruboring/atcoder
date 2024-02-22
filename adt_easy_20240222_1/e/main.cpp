#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;

    map<char, int> mps, mpt;
    rep(i, S.size()) {
        mps[S[i]]++;
        mpt[T[i]]++;
    }

    string atc = "atcoder";
    for (auto [c, cnt] : mps) {
        if ((atc + "@").find(c) != string::npos) continue;
        if (mps[c] != mpt[c]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (auto [c, cnt] : mpt) {
        if ((atc + "@").find(c) != string::npos) continue;
        if (mps[c] != mpt[c]) {
            cout << "No" << endl;
            return 0;
        }
    }
    int s_cnt = mps['@'], t_cnt = mpt['@'];

    for (char c : atc) {
        if (mps[c] < mpt[c]) {
            s_cnt -= mpt[c] - mps[c];
        }
        if (mpt[c] < mps[c]) {
            t_cnt -= mps[c] - mpt[c];
        }
    }

    if (s_cnt >= 0 && t_cnt >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
