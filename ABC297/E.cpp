#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    set<ll> pay;
    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));
    pay.insert(0);
    rep(i, K) {
        pay.insert((i + 1) * A[0]);
    }
    rep(i, N - 1) {
        int cnt = 0;
        for (auto p : pay) {
            if (cnt > K) {
                break;
            }
            pay.insert(p + A[i + 1]);
            cnt++;
        }
    }
    int cnt = 0;
    for (auto p : pay) {
        // cout << p << endl;
        if (cnt == K) {
            cout << p << endl;
        }
        cnt++;
    }
}