#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    ll BASE = 1000000007, ans = 0;
    vector<ll> a(N + 1);
    a[1] = 1;
    a[2] = 1;
    repp(i, 3, N + 1) {
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= BASE;
    }
    cout << a[N] % BASE << endl;
}