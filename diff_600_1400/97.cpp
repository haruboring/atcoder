#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    vector<char> b(10);
    rep(i, 10) cin >> b[i];
    int N;
    cin >> N;
    vector<string> a(N);
    rep(i, N) cin >> a[i];

    map<char, char> mp_fake2real, mp_real2fake;
    rep(i, 10) {
        mp_fake2real[b[i]] = '0' + i;
        mp_real2fake['0' + i] = b[i];
    }

    vector<int> dummy_A(N);
    rep(i, N) {
        string s = a[i];
        rep(j, s.size()) s[j] = mp_fake2real[s[j]];
        dummy_A[i] = stoi(s);
    }

    sort(all(dummy_A));

    rep(i, N) {
        string s = to_string(dummy_A[i]);
        rep(j, s.size()) s[j] = mp_real2fake[s[j]];
        cout << s << endl;
    }
}