#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;
    vector<int> X(Q);
    rep(i, Q) {
        cin >> X[i];
    }
    rep(i, Q) {
        bool is_prime = true;
        repp(j, 2, int(sqrt(X[i]) + 1)) {
            if (X[i] % (j) == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}