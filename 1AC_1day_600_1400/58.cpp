#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));

    deque<ll> B;
    B.push_back(A[0]);
    int r = N, l = 0;
    rep(i, N - 1) {
        if ((i / 2) % 2 == 0) {
            r--;
            if (i % 2 == 0) {
                B.push_back(A[r]);
            } else {
                B.push_front(A[r]);
            }
        } else {
            l++;
            if (i % 2 == 0) {
                B.push_back(A[l]);
            } else {
                B.push_front(A[l]);
            }
        }
    }

    ll ans_B = 0;
    repp(i, 1, N) {
        ans_B += abs(B[i] - B[i - 1]);
    }

    reverse(all(A));
    deque<ll> C;
    C.push_back(A[0]);
    r = N, l = 0;
    rep(i, N - 1) {
        if ((i / 2) % 2 == 0) {
            r--;
            if (i % 2 == 0) {
                C.push_back(A[r]);
            } else {
                C.push_front(A[r]);
            }
        } else {
            l++;
            if (i % 2 == 0) {
                C.push_back(A[l]);
            } else {
                C.push_front(A[l]);
            }
        }
    }

    ll ans_C = 0;
    repp(i, 1, N) {
        ans_C += abs(C[i] - C[i - 1]);
    }

    ll ans = max(ans_B, ans_C);

    cout << ans << endl;
}
