#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int M;
    cin >> M;
    vector<string> S(3);
    cin >> S[0] >> S[1] >> S[2];

    sort(all(S));

    int ans = 1e9;
    do {
        for (int i = 0; i < M; i++) {
            char st = S[0][i];
            for (int j = i + 1; j < i + 1 + M; j++) {
                if (S[1][j % M] != st) continue;
                for (int k = j + 1; k < j + 1 + M; k++) {
                    if (S[2][k % M] != st) continue;
                    ans = min(ans, k);
                }
            }
        }
    } while (next_permutation(all(S)));

    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}