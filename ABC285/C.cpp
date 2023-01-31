#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    ll cnt = 0;
    ll size = S.size();
    rep(i, size) {
        cnt += (ll)(pow(26, i)) * (ll)(S[size - 1 - i] - 'A' + 1);
    }
    cout << cnt << endl;
}