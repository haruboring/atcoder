#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll X, K;
    cin >> X >> K;

    rep(i, K) {
        ll amari = X % ll(pow(10, i + 1));
        if (amari < 5 * ll(pow(10, i))){
            X -= amari;
        }
        else{
            X -= amari;
            X += ll(pow(10, i + 1));
        }
    }
    cout << X << endl;
}