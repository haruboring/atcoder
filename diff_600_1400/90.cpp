#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll A;
    cin >> A;

    repp(i, 10, 10000 + 1) {
        string s = to_string(i);
        ll sum = s[0] - '0';
        repp(j, 1, s.size()) {
            sum *= i;
            sum += s[j] - '0';
        }
        if (i < 30) {
            debug(i);
            debug(sum);
        }

        if (sum == A) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}