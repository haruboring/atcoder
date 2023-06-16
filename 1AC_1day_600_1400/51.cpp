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

    ll sum = 0;
    repp(i, 1, N + 1) {
        sum += i;
        if (sum >= N) {
            repp(j, 1, i + 1) {
                if (j != sum - N) {
                    cout << j << endl;
                }
            }
            return 0;
        }
    }
}