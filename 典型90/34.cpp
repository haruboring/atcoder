#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    set<int> tmp;
    rep(i, N) tmp.insert(A[i]);
    if (tmp.size() <= K) {
        cout << N << endl;
        return 0;
    }

    ll left = 1, right = N;
    while (right - left > 1) {
        // cout << "left: " << left << ", right: " << right << endl;

        ll mid = (left + right) / 2;
        ll cnt = 1e9;
        map<ll, ll> mp;
        set<ll> st;
        rep(i, mid) {
            mp[A[i]]++;
            st.insert(A[i]);
        }
        cnt = max(cnt, (ll)st.size());
        rep(i, N - mid) {
            mp[A[i]]--;
            if (mp[A[i]] == 0) st.erase(A[i]);
            mp[A[i + mid]]++;
            st.insert(A[i + mid]);
            cnt = min(cnt, (ll)st.size());
        }

        if (cnt <= K) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;
}