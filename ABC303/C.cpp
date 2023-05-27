#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    vector<ll> X(M), Y(M);
    set<pair<ll, ll>> st;
    rep(i, M) {
        cin >> X[i] >> Y[i];
        st.insert(make_pair(X[i], Y[i]));
    }

    ll HP = H;
    ll x = 0, y = 0;
    rep(i, N) {
        if (HP <= 0) {
            cout << "No" << endl;
            return 0;
        }
        if (S[i] == 'R') {
            x++;
            HP--;
        }
        if (S[i] == 'L') {
            x--;
            HP--;
        }
        if (S[i] == 'U') {
            y++;
            HP--;
        }
        if (S[i] == 'D') {
            y--;
            HP--;
        }
        if (st.count(make_pair(x, y)) != 0 && HP < K) {
            HP = K;
            st.erase(make_pair(x, y));
        }
    }
    cout << "Yes" << endl;
}