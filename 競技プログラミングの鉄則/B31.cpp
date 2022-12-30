#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll ans = N / 3 + N / 5 + N / 7 - N / 15 - N / 21 - N / 35 + N / 105;
    cout << ans << endl;
}