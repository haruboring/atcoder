#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<string> S(3), T(3);
    rep(i, 3) {
        cin >> S[i];
    }
    int cnt = 0;
    rep(i, 3) {
        cin >> T[i];
        if (S[i] == T[i]) {
            cnt++;
        }
    }
    sort(all(S));
    sort(all(T));
    rep(i, 3) {
        if (S[i] != T[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(cnt == 0 or cnt == 3){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}