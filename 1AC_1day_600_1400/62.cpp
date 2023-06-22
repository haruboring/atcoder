#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int_least32_t main() {
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;

    set<char> st;
    rep(i, S1.size()) st.insert(S1[i]);
    rep(i, S2.size()) st.insert(S2[i]);
    rep(i, S3.size()) st.insert(S3[i]);

    ll size = st.size();
    if (size > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<ll> a(10);
    rep(i, 10) a[i] = i;
    do {
        ll i = 0;
        map<char, ll> mp;
        for (auto c : st) {
            mp[c] = a[i];
            i++;
        }
        ll N1 = 0, N2 = 0, N3 = 0;
        if (mp[S1[0]] == 0 || mp[S2[0]] == 0 || mp[S3[0]] == 0) continue;
        rep(i, S1.size()) {
            N1 *= 10;
            N1 += mp[S1[i]];
        }
        rep(i, S2.size()) {
            N2 *= 10;
            N2 += mp[S2[i]];
        }
        rep(i, S3.size()) {
            N3 *= 10;
            N3 += mp[S3[i]];
        }
        if (N1 + N2 == N3) {
            cout << N1 << endl;
            cout << N2 << endl;
            cout << N3 << endl;
            return 0;
        }
    } while (next_permutation(all(a)));

    cout << "UNSOLVABLE" << endl;
}
