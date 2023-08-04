#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<int, int> mp;
    rep(i, N) {
        mp[A[i] % 200]++;
    }

    ll ans = 0;
    for (auto p : mp) {
        ans += (ll)p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
}