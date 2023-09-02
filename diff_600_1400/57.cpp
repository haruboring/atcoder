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
    vector<ll> C(9);
    rep(i, 9) cin >> C[i];

    ll mn = *min_element(all(C));
    int keta = N / mn;
    string ans = "";
    rep(i, keta) {
        for (int j = 8; j >= 0; j--) {
            if (mn * (keta - 1 - i) + C[j] <= N) {
                ans += to_string(j + 1);
                N -= C[j];
                break;
            }
        }
    }

    cout << ans << endl;
}
