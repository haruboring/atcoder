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
    rep(i, N) cin >> S[i];

    int cnt = 0;
    bool login = false;
    rep(i, N) {
        if (S[i] == "login") {
            login = true;
        } else if (S[i] == "logout") {
            login = false;
        } else if (S[i] == "private") {
            if (!login) cnt++;
        }
    }

    cout << cnt << endl;
}
