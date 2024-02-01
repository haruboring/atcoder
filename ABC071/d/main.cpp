#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<string> S(2);
    cin >> S[0] >> S[1];

    ll MOD = 1e9 + 7;

    int i = 0;

    ll ans = 1;
    while (i < N) {
        if (S[0][i] == S[1][i]) {
            if (i == 0) {
                ans = 3;
            } else if (S[0][i - 1] == S[1][i - 1]) {
                ans = ans * 2 % MOD;
            }
            i++;
        } else {
            if (i == 0) {
                ans = 6;
            } else if (S[0][i - 1] == S[1][i - 1]) {
                ans = ans * 2 % MOD;
            } else {
                ans = ans * 3 % MOD;
            }
            i += 2;
        }
    }

    cout << ans << endl;
}