#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    ll X;
    cin >> X;

    ll money = 100;
    ll year = 0;
    while (money < X) {
        money += money / 100;
        year++;
    }
    cout << year << endl;
}