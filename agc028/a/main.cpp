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
    string S;
    cin >> S;
    string T;
    cin >> T;

    if (N < M) {
        swap(N, M);
        swap(S, T);
    }

    int L = lcm(N, M);
    for (int i = L; i <= N * M; i += L) {
        int s = L / N;
        int t = L / M;

        int l = lcm(s, t);
        bool ok = true;
        for (int j = 0; j < L; j += l) {
            if (S[j / s] != T[j / t]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
