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
    bool excellent = true;
    int cnt = 0;
    rep(i, S.size()) {
        if ('a' <= S[i] && S[i] <= 'z') {
            cnt++;
        }
    }
    if (cnt == (int)S.size()) {
        excellent = false;
    }
    cnt = 0;
    rep(i, S.size()) {
        if ('A' <= S[i] && S[i] <= 'Z') {
            cnt++;
        }
    }
    if (cnt == (int)S.size()) {
        excellent = false;
    }
    set<char> set_S;
    rep(i, S.size()) {
        set_S.insert(S[i]);
    }
    if (set_S.size() != S.size()) {
        excellent = false;
    }
    if (excellent) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}