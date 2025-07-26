#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<string> T(0);
    rep(i, pow(N, K)) {
        vector<int> t(K);
        int ci = i;
        rep(j, K) {
            t[j] = ci % N;
            ci /= N;
        }
        string tm = "";
        rep(j, K) {
            tm += S[t[j]];
        }

        T.push_back(tm);
    }

    sort(all(T));

    cout << T[X - 1] << endl;
}
