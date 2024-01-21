#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    set<char> ss, tt;
    rep(i, N) ss.insert(S[i]);
    rep(i, N) tt.insert(T[i]);

    if (tt.size() == 1 && ss.size() == 2) {
        cout << -1 << endl;
        return 0;
    }
    if (tt.size() == 1 && ss.size() == 1) {
        if (ss.count('A') != tt.count('A')) {
            cout << -1 << endl;
            return 0;
        }
    }

    bool ok = true;

    debug(ok);
    for (int i = N - 1; i >= 0; i--) {
        if (T[i] == 'B') {
            repp(j, i + 1, N) {
                if (S[j] != T[j]) {
                    ok = false;
                    break;
                }
            }
            break;
        }
    }

    debug(ok);

    for (int i = 0; i < N; i++) {
        if (T[i] == 'A') {
            repp(j, 0, i) {
                if (S[j] != T[j]) {
                    ok = false;
                    break;
                }
            }
            break;
        }
    }

    debug(ok);

    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    int lidx = 0;
    bool limit = false;
    rep(i, N) {
        if (S[i] == T[i]) continue;
        S[i] = 'A';
        while (!(S[lidx] != T[lidx] && S[lidx] == 'A')) {
            if (limit) break;
            if (lidx == N - 1) {
                limit = true;
                for (int j = N - 1; j >= 0; j--) {
                    if (S[j] == 'B') {
                        lidx = j;
                        break;
                    }
                }
                break;
            }
            lidx++;
        }
        debug(lidx);
        ans++;
        S[i] = 'A';
        S[lidx] = 'B';
    }

    cout << ans << endl;
}
