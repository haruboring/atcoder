#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, Q) {
        int flag, x;
        cin >> flag >> x;
        if (flag == 3) {
            if (A[x - 1] < 2) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        } else {
            A[x - 1] += flag;
        }
    }
}