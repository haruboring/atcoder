#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    map<ll, ll> mp;
    rep(i, N) {
        mp[0] += b[i];
        mp[a[i]] -= b[i];
    }
    ll cnt = 0;
    for (auto [day, d_cnt] : mp) {
        cnt += d_cnt;
        if (cnt <= K) {
            cout << day << endl;
            return 0;
        }
    }
}