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
    ll A, B;
    cin >> A >> B;

    if (A >= N) {
        cout << "Takahashi" << endl;
        return 0;
    }

    if (A == B) {
        if (N % (A + 1) == 0) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
        return 0;
    }

    if (A > B) {
        cout << "Takahashi" << endl;
        return 0;
    }

    if (A < B) {
        cout << "Aoki" << endl;
        return 0;
    }
}