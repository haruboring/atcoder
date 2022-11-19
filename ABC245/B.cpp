#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(ans, 2020) {
        bool a = true;
        rep(i, N) {
            if (ans == A[i]) {
                a = false;
                break;
            }
        }
        if (a) {
            cout << ans << endl;
            break;
        }
    }
}