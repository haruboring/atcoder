#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll base = K / N;
    ll rem = K % N;

    vector<ll> B = A;
    sort(all(B));
    set<int> s;
    rep(i, rem) {
        debug(B[i]);
        s.insert(B[i]);
    }

    rep(i, N) {
        if (s.count(A[i]))
            cout << base + 1 << endl;
        else
            cout << base << endl;
    }
}