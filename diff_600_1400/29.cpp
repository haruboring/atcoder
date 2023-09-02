#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    int R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;

    ll ans = 0;
    rep(i, N) {
        if (i + K < N) {
            if (T[i] == T[i + K]) {
                T[i + K] = 'x';
            }
        }
        if (T[i] == 'r') ans += P;
        if (T[i] == 's') ans += R;
        if (T[i] == 'p') ans += S;
    }

    cout << ans << endl;
}