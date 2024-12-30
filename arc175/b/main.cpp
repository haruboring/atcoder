#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    int c0 = 0;
    int ok0 = 0;
    rep(i, 2 * N) {
        if (S[i] == '(') {
            ok0++;
        } else {
            ok0--;
        }
        if (ok0 == -1) {
            c0 += B;
            ok0 += 2;
        }
    }
    c0 += (ok0 / 2) * B;

    set<int> l;
    rep(i, 2 * N) if (S[i] == '(') l.insert(i);

    int c = 0;
    if (l.size() < N) {
        c += (N - l.size()) * B;
        int tmp = 0;
        rep(i, 2 * N) {
            if (S[i] == ')') {
                S[i] = '(';
                tmp++;
                if (tmp == N - l.size()) break;
            }
        }
    }
    if (l.size() > N) {
        c += (l.size() - N) * B;
        int tmp = 0;
        for (int i = 2 * N - 1; i >= 0; i--) {
            if (S[i] == '(') {
                S[i] = ')';
                tmp++;
                if (tmp == l.size() - N) break;
            }
        }
    }

    int ok = 0;
    rep(i, 2 * N) {
        if (S[i] == '(') {
            ok++;
            l.erase(i);
        } else {
            ok--;
        }

        if (ok == -1) {
            debug(i);
            if (l.size() > 0) {
                int m = *l.rbegin();
                l.erase(m);
                swap(S[i], S[m]);
                c += A;
            } else {
                S[i] = '(';
                c += B;
            }
            ok += 2;
        }
    }

    cout << min(c, c0) << endl;
}
