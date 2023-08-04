#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    double N;
    cin >> N;
    double ans = 0;
    rep(i, N) {
        ans += (1 / N) * (i + 1) * (10000);
    }
    cout << ans << endl;
}