#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    sort(all(S));
    rep(i, N) cout << S[i];
    cout << endl;
}