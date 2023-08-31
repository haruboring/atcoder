#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    string N;
    ll K;
    cin >> N >> K;

    rep(_, K) {
        ll N10 = 0;
        ll tmp = 1;
        for (ll i = N.size() - 1; i >= 0; i--) {
            N10 += (N[i] - '0') * tmp;
            tmp *= 8;
        }
        string N8 = "";
        while (N10 > 0) {
            N8 += to_string(N10 % 9);
            N10 /= 9;
        }
        rep(i, N8.size()) {
            if (N8[i] == '8') {
                N8[i] = '5';
            }
        }

        reverse(all(N8));

        N = N8;
    }

    if (N == "") N = "0";

    cout << N << endl;
}
