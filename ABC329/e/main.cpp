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

    rep(i, N - M + 1) {
        bool ok = true;
        rep(j, M) if (S[i + j] != T[j]) ok = false;

        if (ok) {
            rep(j, M) S[i + j] = '#';
        }
    }

    debug(S);

    queue<int> q;
    rep(i, N - M + 1) {
        bool ok = true;
        rep(j, M) {
            if (S[i + j] == '#' || S[i + j] == T[j]) continue;
            ok = false;
        }
        if (ok) {
            rep(j, M) if (S[i + j] != '#') q.push(i + j);
        }
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        S[i] = '#';
        repp(j, i - M, i + M) {
            bool ok = true;
            rep(k, M) {
                if (j + k < 0 || j + k >= N) {
                    ok = false;
                    break;
                }
                if (S[j + k] == '#' || S[j + k] == T[k]) continue;
                ok = false;
            }
            if (ok) {
                rep(k, M) if (S[j + k] != '#') q.push(j + k);
            }
        }
    }

    rep(i, N) if (S[i] != '#') {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}
