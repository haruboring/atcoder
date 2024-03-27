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
    string ss;
    cin >> ss;

    vector<int> A = {-1, 1};
    for (auto a : A) {
        for (auto b : A) {
            string s = ss;
            vector<int> ans(N, 0);
            bool ok = true;
            ans[N - 1] = a;
            ans[0] = b;
            rep(i, N) {
                if (ans[i] == -1) {
                    if (s[i] == 'x') {
                        s[i] = 'o';
                    } else {
                        s[i] = 'x';
                    }
                }
                if (s[i] == 'x') {
                    if (ans[(i + 1) % N] == 0) {
                        ans[(i + 1) % N] = -1 * ans[(i - 1 + N) % N];
                    } else {
                        if (ans[(i + 1) % N] != -1 * ans[(i - 1 + N) % N]) {
                            ok = false;
                        }
                    }
                } else {
                    if (ans[(i + 1) % N] == 0) {
                        ans[(i + 1) % N] = ans[(i - 1 + N) % N];
                    } else {
                        if (ans[(i + 1) % N] != ans[(i - 1 + N) % N]) {
                            ok = false;
                        }
                    }
                }
            }
            if (ok) {
                rep(i, N) {
                    if (ans[i] == 1) {
                        cout << 'S';
                    } else {
                        cout << 'W';
                    }
                }
                cout << endl;

                return 0;
            }
        }
    }

    cout << -1 << endl;
}
