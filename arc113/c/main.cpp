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

    reverse(all(S));

    map<char, int> m;
    int cnt = 0;
    rep(i, S.size() - 1) {
        if (S[i] == S[i + 1]) {
            cnt += i - m[S[i]];
            m.clear();
            m[S[i]] = i + 1;
            // cout << "I: " << i << "size" << i+1 << endl;
            // debug(cnt);
        }
        else{
            m[S[i]]++;
        }
    }

    cout << cnt << endl;
}
