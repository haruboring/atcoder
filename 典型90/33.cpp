#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    if (H == 1 || W == 1) {
        cout << max(H, W) << endl;
        return 0;
    }

    cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
}