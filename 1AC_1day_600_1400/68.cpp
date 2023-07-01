#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    rep(_, T) {
        int N;
        cin >> N;
        string S1, S2, S3;
        cin >> S1 >> S2 >> S3;

        string ans = "0";
        rep(i, N) {
            ans += "1";
        }
        rep(i, N) {
            ans += "0";
        }
        cout << ans << endl;
    }
}