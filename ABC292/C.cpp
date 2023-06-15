#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll cnt = 0;
    repp(AB, 1, N) {
        ll CD = N - AB;
        set<ll> ABsoinsu, CDsoinsu;
        repp(i, 1, sqrt(AB) + 1) {
            if (AB % i == 0) {
                ABsoinsu.insert(i);
                ABsoinsu.insert(AB / i);
            }
        }
        repp(i, 1, sqrt(CD) + 1) {
            if (CD % i == 0) {
                CDsoinsu.insert(i);
                CDsoinsu.insert(CD / i);
            }
        }
        cnt += ABsoinsu.size() * CDsoinsu.size();
    }

    cout << cnt << endl;
}