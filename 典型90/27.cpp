#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    set<string> st;

    rep(i, N) {
        if (st.count(S[i]) == 0) {
            cout << i + 1 << endl;
            st.insert(S[i]);
        }
    }
}