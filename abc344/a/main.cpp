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

    int cnt = 0;
    rep(i, S.size()) {
        if (S[i] == '|')
            cnt++;
        else if (cnt % 2 == 0)
            cout << S[i];
    }
    cout << endl;
}
