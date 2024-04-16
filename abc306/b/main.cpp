#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    vector<unsigned long long> A(64);
    rep(i, 64) cin >> A[i];

    unsigned long long ans = 0;
    unsigned long long tmp = 1;
    rep(i, 64) {
        if (A[i] == 1) ans += tmp;
        tmp *= 2;
    }

    cout << ans << endl;
}