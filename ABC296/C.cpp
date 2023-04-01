#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N, X;
    cin >> N >> X;
    X = abs(X);
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));
    ll l = 0, r = 0;
    while (1) {
        if (r >= N || l >= N) {
            break;
        }
        if (A[r] - A[l] == X) {
            cout << "Yes" << endl;
            return 0;
        } else if (A[r] - A[l] < X) {
            r++;
        } else {
            l++;
        }
    }
    cout << "No" << endl;
}