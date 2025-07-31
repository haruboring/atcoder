#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    map<int, int> m;
    rep(i, M) m[T[i] - '0']++;
    rep(i, N) {
        for (int j = 9; j > S[i] - '0'; j--) {
            if (m[j] == 0) continue;
            m[j]--;
            S[i] = j + '0';
            break;
        }
    }

    bool ok = false;
    rep(i, N) if (S[i] == T[M - 1]) ok = true;
    if (!ok) S[N - 1] = T[M - 1];

    cout << S << endl;
}
