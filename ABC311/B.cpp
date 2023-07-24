#include <bits/stdc++.h>

#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, D;
    cin >> N >> D;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    string all = "";
    rep(i, D) {
        rep(j, N + 1) {
            if (j == N) {
                all += 'o';
                break;
            }
            if (S[j][i] == 'x') {
                all += 'x';
                break;
            }
        }
    }

    debug(all);
    int ans = 0;
    rep(i, D) {
        repp(j, i, D) {
            repp(k, i, j + 1) {
                if (all[k] == 'x') break;
                if (k == j) ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << endl;
}