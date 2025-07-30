#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;

    int n = 1;
    int ln = 1, ln_1 = 2;
    while (n < N) {
        int l = ln;
        ln = ln + ln_1;
        ln_1 = l;
        n++;
    }

    cout << ln << endl;
}
