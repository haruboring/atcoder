#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    vector<int> S(8);
    rep(i, 8) cin >> S[i];

    rep(i, 8) {
        if (S[i] < 100 || S[i] > 675 || S[i] % 25 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i, 7) {
        if (S[i] > S[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}