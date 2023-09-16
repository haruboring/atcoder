#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    ll min_ans = (ll)pow(10, 18);
    rep(i, N) {
        ll cnt = 0;
        rep(j, N) {
            if (S[(i + j) % N] != S[(N - 1 - j + i) % N]) {
                cnt++;
            }
        }
        min_ans = min(min_ans, A * i + B * (cnt / 2));
    }
    cout << min_ans << endl;
}