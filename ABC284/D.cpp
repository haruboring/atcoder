#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    vector<ll> test(T);
    rep(i, T) {
        cin >> test[i];
    }
    rep(i, T) {
        ll q, p;
        for (ll a = 2; a < 3 * 1000000 + 100; a++) {
            if (test[i] % a == 0) {
                test[i] /= a;
                if (test[i] % a == 0) {
                    p = a;
                    q = test[i] / a;
                } else {
                    q = a;
                    p = (ll)sqrt(test[i]);
                }
                break;
            }
        }
        cout << p << " " << q << endl;
    }
}