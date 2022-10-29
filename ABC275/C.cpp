#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

map<ll, ll> memo;

ll f(ll N) {
    if (N == 0) {
        memo[0] = 1;
        return 1;
    }
    ll a, b;
    if (memo[N / 2] != 0) {
        a = memo[N / 2];
    } else {
        a = f(N / 2);
    }
    if (memo[N / 3] != 0) {
        b = memo[N / 3];
    } else {
        b = f(N / 3);
    }
    ll ans = a + b;
    memo[N] = ans;
    return ans;
}
 
int main() {
    ll N;
    cin >> N;
    memo[0] = 1;
    cout << f(N) << endl;
}